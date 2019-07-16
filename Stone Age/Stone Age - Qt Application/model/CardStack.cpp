#include "CardStack.h"

#include "Cards/BuildingCard.h"
#include "BuildingCardStack.h"
#include "Cards/CivilisationCard.h"
#include "Game.h"
#include "GameBoard.h"
#include "PlacedCards.h"

CardStack::CardStack(QVector<BuildingCard*> buildingCards, QVector<CivilisationCard*> civilisationCards, int currentBuildingCardIndex = 0, int currentCivilisationCardIndex = 0)
    : m_buildingCardStack{new BuildingCardStack{buildingCards}}, m_civilisationCards{civilisationCards}, m_currentBuildingCardIndex{currentBuildingCardIndex}, m_currentCivilisationCardIndex{currentCivilisationCardIndex} {
    shuffle();
}

void CardStack::shuffle() {
//    std::random_shuffle(m_buildingCards.first(), m_buildingCards.last());
//    std::random_shuffle(m_civilisationCards.first(), m_civilisationCards.last());
}

BuildingCardStack* CardStack::getBuildingCardStack() {
    return m_buildingCardStack;
}

CivilisationCard* CardStack::getNextCivilisationCard() {
    CivilisationCard* civilisationCard{m_civilisationCards.at(m_currentCivilisationCardIndex)};
    m_currentCivilisationCardIndex++;

    return civilisationCard;
}

QVector<CivilisationCard *> CardStack::getCivilCardStack() {
    return m_civilisationCards;
}

int CardStack::getCivilCardIndex() const {
    return m_currentCivilisationCardIndex;
}

void CardStack::setCivilCards(QVector<CivilisationCard *> cards) {
    m_civilisationCards = cards;
}

void CardStack::setCivilCardIndex(int index) {
    m_currentCivilisationCardIndex = index;
}
