#include <QDebug>

#include "../config.h"

#include "PlayerBoard.h"
#include "Cards/BuildingCard.h"
#include "Cards/CivilisationCard.h"
#include "Cards/CivilisationCardFooter.h"
#include "PlayerBoardItems/Food.h"
#include "PlayerBoardItems/ScoreTracker.h"
#include "PlayerBoardItems/FoodTracker.h"
#include "PlayerBoardItems/Resource.h"
#include "PlayerBoardItems/Tools.h"
#include "PlayerBoardItems/Worker.h"
#include "PlayerBoardItems/Workers.h"

#include "Cards/CivilisationCardFooter.h"


PlayerBoard::PlayerBoard(Workers* workers, Food* food, ScoreTracker* scoreTracker,
                         FoodTracker* foodTracker, QVector<Resource*> resourceStock,
                         QVector<BuildingCard*> collectedBuildingCards,
                         QVector<CivilisationCard*> collectedCivilisationCards,
                         Tools* tools) : m_workers{workers}, m_foodStock{food}, m_scoreTracker{scoreTracker},
                                         m_foodTracker{foodTracker}, m_resourceStock{resourceStock}, m_collectedBuildingCards{collectedBuildingCards},
                                         m_collectedCivilisationCard{collectedCivilisationCards}, m_tools{tools} {
    updatePlayerBoard();
}


ScoreTracker* PlayerBoard::getScoreTracker() const {
    return m_scoreTracker;
}

Workers* PlayerBoard::getWorkers() const {
    return m_workers;
}

Food* PlayerBoard::getFoodStock() const {
    return m_foodStock;
}

FoodTracker* PlayerBoard::getFoodTracker() const {
    return m_foodTracker;
}

QVector<Resource*> PlayerBoard::getResourceStock() const {
    return m_resourceStock;
}

QVector<BuildingCard*> PlayerBoard::getCollectedBuildingCards() const {
    return m_collectedBuildingCards;
}

QVector<CivilisationCard*> PlayerBoard::getCollectedCivilisationCards() const {
    return m_collectedCivilisationCard;
}

Tools* PlayerBoard::getTools() const {
    return m_tools;
}

void PlayerBoard::collectBuildingCard(BuildingCard *buildingCard) {
    m_collectedBuildingCards.append(buildingCard);
    this->getScoreTracker()->increaseScore(buildingCard->getReturnPoints());
}

void PlayerBoard::collectCivilisationCard(CivilisationCard *civilisationCard) {
    m_collectedCivilisationCard.append(civilisationCard);
}

int PlayerBoard::getCivlisationCardScore() {
    int totalScore{0};
    QHash<int,int> grassCardTypesCollected{loadCollectedGrassCivilisationCards()};
    QHash<int,int> sandCardTypesCollected{loadCollectedSandCivilisationCards()};

    totalScore += getPointsCollectedGrassCivilisationCards(grassCardTypesCollected);
    totalScore += getPointsCollectedSandCivilisationCards(sandCardTypesCollected);

    return totalScore;
}

void PlayerBoard::setCollectedBuildingCards(QVector<BuildingCard *> cards) {
    m_collectedBuildingCards = cards;
}

void PlayerBoard::setCollectedCivilisationCards(QVector<CivilisationCard *> cards) {
    m_collectedCivilisationCard = cards;
}



QHash<int, int> PlayerBoard::loadCollectedSandCivilisationCards() {
    QHash<int,int> sandCardTypesCollected{};

    // Save all the cardtypes (SAND) and the amount of entities on the collected
    for ( int i{static_cast<int>(CardType::FOOD)}; i != static_cast<int>(CardType::WORKERS); ++i ) {
       sandCardTypesCollected.insert(i, 0);
       for(int j{0}; j < m_collectedCivilisationCard.size(); ++j) {
           CardType cardType = static_cast<CardType>(i);
           CivilisationCardFooter* footer{m_collectedCivilisationCard.at(j)->getCardFooter()};
           if(cardType == footer->getCardType()) {
               sandCardTypesCollected.insert(i, sandCardTypesCollected.value(i) + footer->getAmountOfEntitiesOnCard());
           }
       }
    }

    return sandCardTypesCollected;
}

QHash<int, int> PlayerBoard::loadCollectedGrassCivilisationCards() {
    QHash<int,int> grassCardTypesCollected{};

    // Save all the cardtypes (GRASS) and the amount the player collected
    for ( int i{static_cast<int>(CardType::HEALING)}; i != static_cast<int>(CardType::WEAVING); ++i ) {
        CardType cardType = static_cast<CardType>(i);
        grassCardTypesCollected.insert(i, 0);
       for(int j{0}; j < m_collectedCivilisationCard.size(); ++j) {
           if(cardType == m_collectedCivilisationCard.at(j)->getCardFooter()->getCardType()) {
               grassCardTypesCollected.insert(i, grassCardTypesCollected.value(i) + 1);
           }
       }
    }

    return grassCardTypesCollected;
}

int PlayerBoard::getPointsCollectedSandCivilisationCards(QHash<int,int> sandCardTypesCollected) {
    int totalScore{0};

    for ( int i{static_cast<int>(CardType::FOOD)}; i != static_cast<int>(CardType::WORKERS); ++i ) {
       int points{0};
       CardType cardType = static_cast<CardType>(i);
       int entitiesOnCard{sandCardTypesCollected.value(i)};

       if(cardType == CardType::FOOD)
            points = entitiesOnCard * this->getFoodTracker()->getFoodLevel();
       else if(cardType == CardType::TOOLS)
            points = entitiesOnCard * this->getTools()->getAmountOfTools();
       else if(cardType == CardType::BUILDING)
            points = entitiesOnCard * this->getCollectedBuildingCards().size();
       else if(cardType == CardType::WORKERS)
            points = entitiesOnCard * this->getWorkers()->getWorkersCapacity();

       totalScore += points;
    }

    return totalScore;
}

int PlayerBoard::getPointsCollectedGrassCivilisationCards(QHash<int,int> grassCardTypesCollected) {
    // Set true to go into the while statement
    bool loopValueIsLowerThanMaxInQHash{true};
    int totalScore{0};
    int loopValue{1};

    // Calculate
    while(loopValueIsLowerThanMaxInQHash) {
        // Set to immediatly to false, when a card is found  ==> set to true
        // If no cards are found, it will stay false and loop will end.
        loopValueIsLowerThanMaxInQHash = false;
        int cardCount{0};
        for ( int i{static_cast<int>(CardType::HEALING)}; i != static_cast<int>(CardType::WEAVING); ++i ) {
            int valueInQHash{grassCardTypesCollected.value(i)};

            if(valueInQHash >= loopValue) {
                cardCount++;
                loopValueIsLowerThanMaxInQHash = true;
            }
        }
        totalScore += (cardCount * cardCount);
    }

    return totalScore;
}

void PlayerBoard::updatePlayerBoard() {

    QString workers{QString::number(m_workers->getAvailableWorkers().count()) + "/" + QString::number(m_workers->getWorkersCapacity())};
    QString food{QString::number(m_foodStock->getFoodSupply())};
    QString score{"Score: " + QString::number(m_scoreTracker->getScore())};
    QString wood{QString::number(m_resourceStock.at(WOOD_RESOURCE)->getCurrentAmount())};
    QString stone{QString::number(m_resourceStock.at(STONE_RESOURCE)->getCurrentAmount())};
    QString brick{QString::number(m_resourceStock.at(BRICK_RESOURCE)->getCurrentAmount())};
    QString gold{QString::number(m_resourceStock.at(GOLD_RESOURCE)->getCurrentAmount())};

    emit s_updatePlayerBoard(workers, food, score, wood, stone, brick, gold, m_tools);
    //    emit s_setActiveState(true);
}

void PlayerBoard::setActive() {
    emit s_setActiveState(true);


}

void PlayerBoard::unsetActive() {
    emit s_setActiveState(false);
}


