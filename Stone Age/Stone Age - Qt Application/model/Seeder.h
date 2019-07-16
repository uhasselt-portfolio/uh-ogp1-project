#ifndef SEEDER_H
#define SEEDER_H

#include <QVector>

#include "Team.h"

class Player;
class Players;
class GameBoard;
class PlayerBoard;
class Places;
class Food;
class Workers;
class ScoreTracker;
class FoodTracker;
class Resource;
class BuildingCard;
class CivilisationCard;
class Tools;
class Game;
class GameRoundManager;
class CardStack;
class PlacedCards;
class BuildingCardPlace;
class CivilisationCardPlace;

class Seeder {

    public:
        // Constructor
        Seeder();

        // Utils
        Players* loadPlayers(Game* game);
        GameBoard* loadGameBoard(Game* game);
        PlayerBoard* loadPlayerBoard(Team team, Game* game=nullptr);
        GameRoundManager* loadGameRounds(Players* players, Game* game);

    private:
        // Utils
        Places* loadPlaces(Game* game, QVector<BuildingCardPlace*> buildingCardPlaces, QVector<CivilisationCardPlace*> civilisationCardPlace);
        Food* loadFood();
        ScoreTracker* loadScoreTracker();
        FoodTracker* loadFoodTracker();
        QVector<Resource*> loadResourceStock();
        QVector<BuildingCard*> loadCollectedBuildingCards(Game* game);
        QVector<CivilisationCard*> loadCollectedCivilisationCards();
        QVector<BuildingCard*> loadCardStackBuildingCards(Game* game);
        QVector<CivilisationCard*> loadCardStackCivilisationCards(Game* game);
        int loadCurrentBuildingCardIndex();
        int loadCurrentCivilisationCardIndex();
        Tools* loadTools(Game* game);
};
#endif // SEEDER_H
