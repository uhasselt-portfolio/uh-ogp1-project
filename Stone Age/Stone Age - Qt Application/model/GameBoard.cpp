#include "GameBoard.h"
#include "Places.h"
#include "PlacedCards.h"
#include "CardStack.h"
#include "GameBoard.h"

#include "Places/BuildingCardPlace.h"
#include "Places/CivilisationCardPlace.h"

GameBoard::GameBoard(Places* places, PlacedCards* placedCards, CardStack* cardStack)
    : m_places{places}, m_placedCards{placedCards}, m_cardStack{cardStack} {
}

Places* GameBoard::getPlaces() const {
    return m_places;
}

PlacedCards* GameBoard::getPlacedCards() const {
    return m_placedCards;
}

CardStack* GameBoard::getCardStack() const {
    return m_cardStack;
}

bool GameBoard::isValidMove() const {
    return false;
}

BuildingCardPlace *GameBoard::getActiveBuildingCardPlace() const {
    return m_activeBuildingCardPlace;
}
CivilisationCardPlace *GameBoard::getActiveCivilCardPlace() const {
    return m_activeCivilCardPlace;
}


void GameBoard::setActiveBuildingCardPlace(BuildingCardPlace *place) {
    m_activeBuildingCardPlace = place;
    m_activeCivilCardPlace = nullptr;
}
void GameBoard::setActiveCivilCardPlace(CivilisationCardPlace *place) {
    m_activeCivilCardPlace = place;
    m_activeBuildingCardPlace = nullptr;
}
