#include <QDebug>

#include "BuildingCardPlace.h"
#include "../Cards/BuildingCard.h"
#include "../../config.h"

#include "../Game.h"
#include "../Players.h"
#include "../Player.h"
#include "../PlayerBoard.h"
#include "../GameBoard.h"
#include "../GameRoundManager.h"
#include "../PlayerBoardItems/Worker.h"
#include "../PlayerBoardItems/Workers.h"
#include "../PlayerBoardItems/ScoreTracker.h"
#include "../PlayerBoardItems/Resource.h"

#include "../Cards/RangedResourceBuildingCard.h"
#include "../Cards/SpecificResourceBuildingCard.h"
#include "../Cards/SelectedResourceBuildingCard.h"

// Constructor
BuildingCardPlace::BuildingCardPlace(BuildingCard* buildingCard, Game* game) :
    Place{"Building Card", 1, game}, m_buildingCard{buildingCard}, m_tempResources{0, 0, 0, 0} {}


// Getters
BuildingCard* BuildingCardPlace::getBuildingCard() const {
    return m_buildingCard;
}
void BuildingCardPlace::setBuildingCard(BuildingCard *buildingCard) {
    m_buildingCard = buildingCard;
}

// Setters
void BuildingCardPlace::resetTempResources() {
    m_tempResources = {0, 0, 0, 0};
}
void BuildingCardPlace::addTempResources(int wood, int brick, int stone, int gold) {
    QVector<int> resources{wood, brick, stone, gold};
    addTempResources(resources);
}
void BuildingCardPlace::addTempResources(QVector<int> resources) {
    for(int i{0}; i < AMOUNT_RESOURCE_TYPES; ++i) {
        if (m_tempResources[i] < 7 || resources[i] < 0)
            m_tempResources[i] += resources[i];

        if (m_tempResources[i] < 0)
            m_tempResources[i] = 0;
    }

    emit s_announcePayResources(this, nullptr, m_tempResources);
}

void BuildingCardPlace::removeTempResources(int wood, int brick, int stone, int gold) {
    QVector<int> resources{-wood, -brick, -stone, -gold};
    addTempResources(resources);
}


// Utils
/**
* Setup the collect process of a building card. The user can either pay if it is a specific building card or change the resources to pay (announce in the view).
*/
void BuildingCardPlace::collect() {
    resetTempResources();

    if(m_currentWorkers.size() > 0) {
        Team teamOnCard{m_currentWorkers.at(0)->getTeam()};
        if(m_game->getGameRoundManager()->getPhase() == 2) {
            if(m_game->getPlayers()->getCurrentPlayer()->getTeam() == teamOnCard) {
                qDebug() << "@BuildingCardPlace - Waiting for pay...";

                m_game->getGameBoard()->setActiveBuildingCardPlace(this);
                int classType{m_buildingCard->getType()};

                if (classType == 0)
                    emit s_announcePayResources(this, nullptr, BuildingCard::convertResources(reinterpret_cast<SpecificResourceBuildingCard*>(m_buildingCard)->getRequiredResources()), false);
                else
                    emit s_announcePayResources(this, nullptr, QVector<int>{0, 0, 0, 0});

            }
            else {
                m_game->announce("Dit is niet jouw werker!");
            }
        }
    }
    else {
        if(m_game->getGameRoundManager()->getPhase() == 2)
            m_game->announce("Geen werkers op deze bouwkaart!");
        else
            handleClickEvent();
    }
}

/**
* Pay for the building card or give appropriate feedback to the user
*/
void BuildingCardPlace::pay() {
    qDebug() << "@BuildingCardPlace - Paying resources...";

    // Check if you have enough resources
    for(int i{0}; i < AMOUNT_RESOURCE_TYPES; ++i) {
        QVector<Resource*> resourceStock{m_game->getPlayers()->getCurrentPlayer()->getPlayerBoard()->getResourceStock()};

        if (resourceStock.at(i)->getCurrentAmount() < m_tempResources[i]) {
            m_game->announce("Je hebt niet genoeg resources voor deze kaart!");
            resetTempResources();
            return;
        }
    }

    // Pay for resources
    m_buildingCard->setGivenResources(BuildingCard::convertResourcesBack(m_tempResources));
    if(m_buildingCard->checkValidResources()) {
        Player* currentPlayer{m_game->getPlayers()->getCurrentPlayer()};
        currentPlayer->getPlayerBoard()->collectBuildingCard(m_buildingCard);
        m_game->getPlayers()->updateBuildingCardInventory();
        emit s_removeBuildingCardView();

        QVector<Resource*> resourceStock{currentPlayer->getPlayerBoard()->getResourceStock()};
        for (int i{0}; i < AMOUNT_RESOURCE_TYPES; ++i) {
            resourceStock.at(i)->decreaseAmount(m_tempResources[i]);
        }
        currentPlayer->getPlayerBoard()->getScoreTracker()->increaseScore(m_buildingCard->getReturnPoints());

        m_buildingCard = nullptr;
        handleClickEvent();
    }
    else {
        m_game->announce("Meegegeven resources voldoen niet aan de eisen van deze kaart!");
    }

    resetTempResources();
}

/**
* Add a visual card to (this) building card place
*/
void BuildingCardPlace::addCardView(QString imageName) {
    emit s_addBuildingCardView(imageName);
}
