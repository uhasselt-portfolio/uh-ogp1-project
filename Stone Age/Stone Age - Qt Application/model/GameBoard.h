#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class Place;
class Places;
class PlacedCards;
class CardStack;
class BuildingCardPlace;
class CivilisationCardPlace;

class GameBoard {
    public:
        // Constructor
        GameBoard(Places* places, PlacedCards* placedCards, CardStack* cardStack);

        // Getters
        Places* getPlaces() const;
        PlacedCards* getPlacedCards() const;
        CardStack* getCardStack() const;
        bool isValidMove() const;
        BuildingCardPlace *getActiveBuildingCardPlace() const;
        CivilisationCardPlace *getActiveCivilCardPlace() const;

        // Setters
        void setActiveBuildingCardPlace(BuildingCardPlace *place);
        void setActiveCivilCardPlace(CivilisationCardPlace *place);

    private:
        Places* m_places;
        PlacedCards* m_placedCards;
        CardStack* m_cardStack;

        BuildingCardPlace* m_activeBuildingCardPlace;
        CivilisationCardPlace* m_activeCivilCardPlace;
};

#endif // GAMEBOARD_H
