#ifndef PLACEDCARDS_H
#define PLACEDCARDS_H

#include <QVector>

#include "Team.h"

class BuildingCardPlace;
class CivilisationCardPlace;
class CardStack;
class Game;

class PlacedCards {
    public:
        // Constructor
        PlacedCards(CardStack* cardStack, Game* game);

        // Getters
        QVector<BuildingCardPlace*> getPlacedBuildingCards() const;
        QVector<CivilisationCardPlace*> getPlacedCivilisationCards() const;
        bool hasWorkers(Team team) const;
        bool isCivilisationCardStackEmpty() const;

        // Utils
        void refillCards();

    private:
        Game* m_game;
        CardStack* m_cardStack;
        QVector<BuildingCardPlace*> m_buildingCardPlaces;
        QVector<CivilisationCardPlace*> m_civilisationCardPlaces;
};

#endif // PLACEDCARDS_H
