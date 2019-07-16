#include <QDebug>

#include "SpecificResourceBuildingCard.h"
#include "../../config.h"
#include "../PlayerBoardItems/Resource.h"
#include "../Game.h"
#include "../Players.h"
#include "../Player.h"
#include "../PlayerBoard.h"
#include "../PlayerBoardItems/Resource.h"

// Constructor
SpecificResourceBuildingCard::SpecificResourceBuildingCard(int returnPoints, QString imagePath, QVector<Resource*> requiredResources, Game* game) :
    BuildingCard{returnPoints, imagePath, game}, m_requiredResources{requiredResources} {}

// Getters
QVector<Resource*> SpecificResourceBuildingCard::getRequiredResources() const {
    return m_requiredResources;
}

// Abstract
bool SpecificResourceBuildingCard::checkValidResources() const {
    qDebug() << "Check valid resources...";
    PlayerBoard* currentPlayerBoard{m_game->getPlayers()->getCurrentPlayer()->getPlayerBoard()};

    bool isValid{true};

    for(int i{0}; i < AMOUNT_RESOURCE_TYPES; i++) {
        for(int j{0}; j < m_requiredResources.size(); ++j) {
            if(m_requiredResources.at(j)->getType() == currentPlayerBoard->getResourceStock().at(j)->getType()) {
                int resourceAmount{currentPlayerBoard->getResourceStock().at(j)->getCurrentAmount()};
                if(resourceAmount < m_requiredResources.at(j)->getCurrentAmount())
                    isValid = false;
            }
        }
    }
    return isValid;
}
int SpecificResourceBuildingCard::getReturnPoints() const {
    return m_returnPoints;
}


