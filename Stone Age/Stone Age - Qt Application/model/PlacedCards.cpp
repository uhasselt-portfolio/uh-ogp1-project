#include "PlacedCards.h"
#include "../config.h"

#include "Places/BuildingCardPlace.h"
#include "Places/CivilisationCardPlace.h"
#include "Cards/BuildingCard.h"
#include "BuildingCardStack.h"
#include "Cards/CivilisationCard.h"
#include "CardStack.h"
#include "Game.h"

// Contructors
PlacedCards::PlacedCards(CardStack* cardStack, Game* game) : m_cardStack{cardStack}, m_buildingCardPlaces{}, m_civilisationCardPlaces{}, m_game{game} {
    refillCards();
}

// Getters
QVector<BuildingCardPlace*> PlacedCards::getPlacedBuildingCards() const {
    return m_buildingCardPlaces;
}

QVector<CivilisationCardPlace*> PlacedCards::getPlacedCivilisationCards() const {
    return m_civilisationCardPlaces;
}

bool PlacedCards::hasWorkers(Team team) const {

    for(int i{0}; i < m_buildingCardPlaces.size(); ++i)
        if(m_buildingCardPlaces.at(i)->hasWorkers(team))
            return true;

    for(int i{0}; i < m_civilisationCardPlaces.size(); ++i)
        if(m_civilisationCardPlaces.at(i)->hasWorkers(team))
            return true;

    return false;
}

// Utils
void PlacedCards::refillCards() {
    for(int i{0}; i < CARD_AMOUNT_ON_BOARD; ++i) {
        if(m_buildingCardPlaces.size() < CARD_AMOUNT_ON_BOARD) {
            m_buildingCardPlaces.append(new BuildingCardPlace{m_cardStack->getBuildingCardStack()->getBuildingCardFromStack(i), m_game});
        } else if(m_buildingCardPlaces.at(i)->getBuildingCard() == nullptr) {
            BuildingCard* newBuildingCard{m_cardStack->getBuildingCardStack()->getBuildingCardFromStack(i)};
            m_buildingCardPlaces.at(i)->setBuildingCard(newBuildingCard);
            m_buildingCardPlaces.at(i)->addCardView(newBuildingCard->getImagePath());
        }
    }

    // TODO
    for(int i{0}; i < CARD_AMOUNT_ON_BOARD; ++i) {
        if(m_civilisationCardPlaces.size() < CARD_AMOUNT_ON_BOARD) {
            m_civilisationCardPlaces.append(new CivilisationCardPlace{m_cardStack->getNextCivilisationCard(), m_game, 4 - i});
        } else if(m_civilisationCardPlaces.at(i)->getCivilisationCard() == nullptr) {
            CivilisationCard* newCivilisationCard{m_cardStack->getNextCivilisationCard()};
            m_civilisationCardPlaces.at(i)->setCivilisationCard(newCivilisationCard);
            m_civilisationCardPlaces.at(i)->addCardView(newCivilisationCard->getImagePath());
        }
    }
}

// This function must be called after refillCards to return the right data
bool PlacedCards::isCivilisationCardStackEmpty() const {
    for(int i{0}; i < CARD_AMOUNT_ON_BOARD; ++i) {
        if(m_civilisationCardPlaces.at(i)->getCivilisationCard() == nullptr)
            return true;
    }
    return false;
}




