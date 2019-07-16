#include <QDebug>

#include "CivilisationCardPlace.h"
#include "../Cards/CivilisationCard.h"
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

// Constructor
CivilisationCardPlace::CivilisationCardPlace(CivilisationCard *civilisationCard, Game *game, int resourceAmount)
    : Place{"Civilisation Card", 1, game}, m_civilisationCard{civilisationCard}, m_tempResources{0, 0, 0, 0}, m_resourceAmount{resourceAmount} {

}

CivilisationCard *CivilisationCardPlace::getCivilisationCard() const {
    return m_civilisationCard;
}

// Setters
void CivilisationCardPlace::setCivilisationCard(CivilisationCard* civilisationCard) {
    m_civilisationCard = civilisationCard;
}

void CivilisationCardPlace::resetTempResources() {
    m_tempResources = {0, 0, 0, 0};
}
void CivilisationCardPlace::addTempResources(int wood, int brick, int stone, int gold) {
    QVector<int> resources{wood, brick, stone, gold};
    addTempResources(resources);
}
void CivilisationCardPlace::addTempResources(QVector<int> resources) {
    for(int i{0}; i < AMOUNT_RESOURCE_TYPES; ++i) {
        if (m_tempResources[i] < 7 || resources[i] < 0)
            m_tempResources[i] += resources[i];

        if (m_tempResources[i] < 0)
            m_tempResources[i] = 0;
    }

    emit s_announcePayResources(nullptr, this, m_tempResources);
}

void CivilisationCardPlace::removeTempResources(int wood, int brick, int stone, int gold) {
    QVector<int> resources{-wood, -brick, -stone, -gold};
    addTempResources(resources);
}

void CivilisationCardPlace::collect() {
    resetTempResources();

    if(m_currentWorkers.size() > 0) {
        Team teamOnCard{m_currentWorkers.at(0)->getTeam()};
        if(m_game->getGameRoundManager()->getPhase() == 2) {
            if(m_game->getPlayers()->getCurrentPlayer()->getTeam() == teamOnCard) {
                qDebug() << "@CivilCardPlace - Waiting for payment...";
                m_game->getGameBoard()->setActiveCivilCardPlace(this);

                emit s_announcePayResources(nullptr, this, QVector<int>{0, 0, 0, 0});

            } else {
                m_game->announce("Dit is niet jouw werker!");
            }
        }
    } else {
        if(m_game->getGameRoundManager()->getPhase() == 2)
            m_game->announce("Geen werkers op deze bouwkaart!");
        else
            handleClickEvent();
    }
}

void CivilisationCardPlace::pay() {
    qDebug() << "@CivilCardPlace - Payment recieved...";

    // Check if the amount of res is correct
    int resSum{0};
    foreach(int resAmount, m_tempResources) {
        resSum += resAmount;
    }


    if (resSum == m_resourceAmount) {
        // Check if you have enough resources
        for(int i{0}; i < AMOUNT_RESOURCE_TYPES; ++i) {
            QVector<Resource*> resourceStock{m_game->getPlayers()->getCurrentPlayer()->getPlayerBoard()->getResourceStock()};

            if (resourceStock.at(i)->getCurrentAmount() < m_tempResources[i]) {
                m_game->announce("Je hebt niet de juiste resources voor deze kaart!");
                resetTempResources();
                return;
            }
        }

        // Pay
        QVector<Resource*> resourceStock{m_game->getPlayers()->getCurrentPlayer()->getPlayerBoard()->getResourceStock()};
        for (int i{0}; i < AMOUNT_RESOURCE_TYPES; ++i) {
            resourceStock.at(i)->decreaseAmount(m_tempResources[i]);
        }


        // Increase with recieved items
        m_civilisationCard->executeHeader();

        m_game->getPlayers()->getCurrentPlayer()->getPlayerBoard()->collectCivilisationCard(m_civilisationCard);
        m_civilisationCard = nullptr;
        m_game->getPlayers()->updateCivilisationCardInventory();
        emit s_removeCivlisationCardView();
        handleClickEvent();

        resetTempResources();
    }
}



void CivilisationCardPlace::addCardView(QString imageName) {
    emit s_addCivilisationCardView(imageName);
}

