#include <QDebug>

#include "Seeder.h"
#include "../config.h"
#include "Player.h"
#include "Players.h"
#include "GameBoard.h"
#include "PlayerBoard.h"
#include "Places.h"
#include "./PlayerBoardItems/Food.h"
#include "./PlayerBoardItems/Workers.h"
#include "./PlayerBoardItems/ScoreTracker.h"
#include "./PlayerBoardItems/FoodTracker.h"
#include "./PlayerBoardItems/Resource.h"
#include "./PlayerBoardItems/Tools.h"
#include "./PlayerBoardItems/Tool.h"
#include "./Places/ClayPitPlace.h"
#include "./Places/FieldPlace.h"
#include "./Places/ForestPlace.h"
#include "./Places/HuntPlace.h"
#include "./Places/HutPlace.h"
#include "./Places/QuarryPlace.h"
#include "./Places/RiverPlace.h"
#include "./Places/ToolMakerPlace.h"
#include "GameRoundManager.h"
#include "CardStack.h"
#include "Cards/BuildingCard.h"
#include "PlacedCards.h"
#include "Places/BuildingCardPlace.h"
#include "Cards/SpecificResourceBuildingCard.h"

#include "FileHandler.h"

// Constructor
Seeder::Seeder() {

}


// Utils
Players* Seeder::loadPlayers(Game* game) {
    QVector<Player*> players{};
    players.append(new Player{"Ingo", Team::RED, game});
    players.append(new Player{"Michiel", Team::BLUE, game});
    players.append(new Player{"Brent", Team::GREEN, game});
    players.append(new Player{"Wouter", Team::YELLOW, game});
    return new Players{players, game};
}

GameBoard* Seeder::loadGameBoard(Game* game) {
    CardStack* cardStack{new CardStack{
                loadCardStackBuildingCards(game),
                loadCardStackCivilisationCards(game),
                loadCurrentBuildingCardIndex(),
                loadCurrentCivilisationCardIndex()
    }};
    PlacedCards* placedCards{new PlacedCards{cardStack, game}};
    Places* places = loadPlaces(game, placedCards->getPlacedBuildingCards(), placedCards->getPlacedCivilisationCards());
    return new GameBoard{places, placedCards, cardStack};
}

Places* Seeder::loadPlaces(Game* game, QVector<BuildingCardPlace*> buildingCardPlaces, QVector<CivilisationCardPlace*> civilisationCardPlace) {
    ToolMakerPlace* toolMaker = new ToolMakerPlace{"Tool Maker", 1, game};
    ClayPitPlace* clayPit = new ClayPitPlace{"Clay Pit", 7, game};
    FieldPlace* field = new FieldPlace{"Field", 1, game};
    ForestPlace* forest = new ForestPlace{"Forest", 7, game};
    HuntPlace* hunt =new HuntPlace{"Hunt", INFINITE, game};
    HutPlace* hut = new HutPlace{"Hut", 2, game};
    QuarryPlace* quarry = new QuarryPlace{"Quarry", 7, game};
    RiverPlace* river = new RiverPlace{"River", 7, game};
    return new Places(hut, hunt, field, river, forest, quarry, clayPit, toolMaker, buildingCardPlaces, civilisationCardPlace);
}

GameRoundManager* Seeder::loadGameRounds(Players* players, Game* game) {
    return new GameRoundManager{players, 1, 1, 0, game};
}

PlayerBoard* Seeder::loadPlayerBoard(Team team, Game* game) {
    Food* food{loadFood()};
    ScoreTracker* scoreTracker{loadScoreTracker()};
    FoodTracker* foodTracker{loadFoodTracker()};
    Workers* workers{new Workers{team, 6, food, scoreTracker, foodTracker}};
    QVector<Resource*> resourceStock{loadResourceStock()};
    QVector<BuildingCard*> collectedBuildingCards{loadCollectedBuildingCards(game)};
    QVector<CivilisationCard*> collectedCivilisationCards{loadCollectedCivilisationCards()};
    Tools* tools{loadTools(game)};
    PlayerBoard* playerBoard{new PlayerBoard(
                        workers, food, scoreTracker, foodTracker,
                        resourceStock, collectedBuildingCards,
                        collectedCivilisationCards, tools
                    )};
    return playerBoard;
}

Food* Seeder::loadFood() {
    Food* food{new Food{0}};
    return food;
}

ScoreTracker* Seeder::loadScoreTracker() {
    ScoreTracker* scoreTracker{new ScoreTracker{0}};
    return scoreTracker;
}

FoodTracker* Seeder::loadFoodTracker() {
    FoodTracker* foodTracker{new FoodTracker{0}};
    return foodTracker;
}

QVector<Resource*> Seeder::loadResourceStock() {
    QVector<Resource*> resource;
    Resource* wood{new Resource(3, 0, ResourceType::WOOD)};
    Resource* brick{new Resource(4, 0, ResourceType::BRICK)};
    Resource* stone{new Resource(5, 0, ResourceType::STONE)};
    Resource* gold{new Resource(6, 0, ResourceType::GOLD)};
    resource.append(wood);
    resource.append(brick);
    resource.append(stone);
    resource.append(gold);
    return resource;
}

QVector<BuildingCard*> Seeder::loadCollectedBuildingCards(Game* game) {
    (void)game;
    QVector<BuildingCard*> collectedBuildingCards{};
    return collectedBuildingCards;
}

QVector<CivilisationCard*> Seeder::loadCollectedCivilisationCards() {
    QVector<CivilisationCard*> collectedCivilisationCards{};
    return collectedCivilisationCards;
}

QVector<BuildingCard*> Seeder::loadCardStackBuildingCards(Game* game) {
    QVector<BuildingCard*> cardStackBuildingCards{ (new FileHandler{game})->importBuildingCards() };
    return cardStackBuildingCards;
}
QVector<CivilisationCard*> Seeder::loadCardStackCivilisationCards(Game* game) {
    QVector<CivilisationCard*> cardStackCivilisationCards{(new FileHandler{game})->importCivilisationCards()};
    return cardStackCivilisationCards;
}
int Seeder::loadCurrentBuildingCardIndex() {
    return 0;
}
int Seeder::loadCurrentCivilisationCardIndex() {
    return 0;
}

Tools* Seeder::loadTools(Game* game) {
    QVector<Tool*> tools{};
    return new Tools{tools, game};
}
