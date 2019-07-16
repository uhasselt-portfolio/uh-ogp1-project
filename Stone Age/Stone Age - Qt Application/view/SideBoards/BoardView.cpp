#include <QDebug>
#include <QString>
#include <QTextStream>

#include "BoardView.h"
#include "../../config.h"

#include "../Places/PlaceView.h"
#include "../Places/ForestView.h"
#include "../Places/ClayPitView.h"
#include "../Places/QuarryView.h"
#include "../Places/RiverView.h"
#include "../Places/FieldView.h"
#include "../Places/ToolMakerView.h"
#include "../Places/HutView.h"
#include "../Places/HuntView.h"
#include "../Places/CivilisationCardView.h"
#include "../Places/BuildingCardView.h"
#include "../Cards/CardView.h"

#include "../../model/Game.h"
#include "../../model/Places/ForestPlace.h"
#include "../../model/Places/ClayPitPlace.h"
#include "../../model/Places/QuarryPlace.h"
#include "../../model/Places/RiverPlace.h"
#include "../../model/Places/FieldPlace.h"
#include "../../model/Places/ToolMakerPlace.h"
#include "../../model/Places/HutPlace.h"
#include "../../model/Places/HuntPlace.h"
#include "../../model/Places/BuildingCardPlace.h"
#include "../../model/Places/CivilisationCardPlace.h"
#include "../../model/GameBoard.h"
#include "../../model/Places.h"
#include "../../model/Players.h"
#include "../../model/Player.h"
#include "../../model/PlayerBoard.h"
#include "../../model/PlayerBoardItems/FoodTracker.h"
#include "../../model/Cards/BuildingCard.h"
#include "../../model/Cards/CivilisationCard.h"

#include "../Items/FoodMarkerView.h"
#include "../../model/PlacedCards.h"



// Constructor
BoardView::BoardView(int x, int y, int h, QGraphicsScene* scene, Game* game) : QGraphicsPixmapItem{QPixmap{":images/images/board.jpg"}.scaledToHeight(h*SCALE)}, m_game{game} {
    setPos(x*SCALE, y*SCALE);

    if (scene != nullptr)
        scene->addItem(this);

    initRecoursePlaces();
    initCardPlaces();
    initFoodMarkers();
}


// Init
void BoardView::initRecoursePlaces() {
    // WOOD PEOPLE
    ForestPlace* forest = m_game->getGameBoard()->getPlaces()->getForest();
    ForestView *forestView = new ForestView{220, 55, 120, 150, this, m_game, forest};
    QVector<QPoint> forestCoords{QPoint(39,26), QPoint(66,34), QPoint(46,47), QPoint(75,52), QPoint(39,67), QPoint(65,69), QPoint(77,85)};
    forestView->setCoordinates(forestCoords);
    m_places.append(forestView);

    // CLAY PEOPLE
    ClayPitPlace* clayPit = m_game->getGameBoard()->getPlaces()->getClayPit();
    ClayPitView *clayPitView = new ClayPitView{370, 50, 172, 90, this, m_game, clayPit};
    QVector<QPoint> clayPitCoords{QPoint(18,39), QPoint(45,51), QPoint(53,34), QPoint(80,29), QPoint(77,50), QPoint(111,53), QPoint(107,35)};
    clayPitView->setCoordinates(clayPitCoords);
    m_places.append(clayPitView);

    // STONE PEOPLE
    QuarryPlace* quarry = m_game->getGameBoard()->getPlaces()->getQuarry();
    QuarryView *quarryView = new QuarryView{675, 50, 110, 130, this, m_game, quarry};
    QVector<QPoint> quarryCoords{QPoint(22,25), QPoint(52,28), QPoint(42,43), QPoint(71,44), QPoint(49,59), QPoint(75,65), QPoint(65,88)};
    quarryView->setCoordinates(quarryCoords);
    m_places.append(quarryView);

    // GOLD PEOPLE
    RiverPlace* river = m_game->getGameBoard()->getPlaces()->getRiver();
    RiverView *riverView = new RiverView{565, 185, 160, 140, this, m_game, river};
    QVector<QPoint> riverCoords{QPoint(40,15), QPoint(68,13), QPoint(97,17), QPoint(33,31), QPoint(62,28), QPoint(89,35), QPoint(66,49)};
    riverView->setCoordinates(riverCoords);
    m_places.append(riverView);

    // FARM PEOPLE
    FieldPlace* field = m_game->getGameBoard()->getPlaces()->getField();
    FieldView *fieldView = new FieldView{130, 240, 175, 110, this, m_game, field};
    QVector<QPoint> fieldCoords{QPoint(112,48)};
    fieldView->setCoordinates(fieldCoords);
    m_places.append(fieldView);

    // TOOLS PEOPLE
    ToolMakerPlace* toolMaker = m_game->getGameBoard()->getPlaces()->getToolMaker();
    ToolMakerView *toolMakerView = new ToolMakerView{363 , 198, 160, 140, this, m_game, toolMaker};
    QVector<QPoint> toolMakerCoords{QPoint(72,64)};
    toolMakerView->setCoordinates(toolMakerCoords);
    m_places.append(toolMakerView);

    // LOVE PEOPLE
    HutPlace* hut = m_game->getGameBoard()->getPlaces()->getHut();
    HutView *hutView = new HutView{275, 326, 85, 80, this, m_game, hut};
    QVector<QPoint> hutCoords{QPoint(29,43), QPoint(55,38)};
    hutView->setCoordinates(hutCoords);
    m_places.append(hutView);

    // HUNT PEOPLE
    HuntPlace* hunt = m_game->getGameBoard()->getPlaces()->getHunt();
    HuntView *huntView = new HuntView{50, 70, 160, 220, this, m_game, hunt};
    huntView->genCoordinates(40);
    m_places.append(huntView);
}
void BoardView::initCardPlaces() {
    // TOOL CARDS (STATIC)
    CardView* tool1 = new CardView{":/images/images/tools/tool1.jpg", 392*SCALE, 293*SCALE, 36};
    tool1->setParentItem(this);
    CardView* tool2 = new CardView{":/images/images/tools/tool1.jpg", 461*SCALE, 293*SCALE, 36};
    tool2->setParentItem(this);

    m_game->getGameBoard()->getPlacedCards()->refillCards();

    QVector<CivilisationCardPlace*> civilisationCardPlaces {m_game->getGameBoard()->getPlacedCards()->getPlacedCivilisationCards()};

    for(int i{0}; i < civilisationCardPlaces.size(); ++i) {
        CivilisationCardView* civilisationPlaceView = new CivilisationCardView{415 + (i * 94), 380, 94, 140, civilisationCardPlaces.at(i), this};
        civilisationPlaceView->setCoordinates(QVector<QPoint>{QPoint{60, 47}});
        civilisationPlaceView->addCard(new CardView{":/images/images/cards/civil/" + civilisationCardPlaces.at(i)->getCivilisationCard()->getImagePath() + ".jpg", 0, 0, 85});
        m_civilisationCards.append(civilisationPlaceView);
    }

    QVector<BuildingCardPlace*> buildingCards{m_game->getGameBoard()->getPlacedCards()->getPlacedBuildingCards()};

    for(int i{0}; i < buildingCards.size(); ++i) {
        BuildingCardView *buildingPlace = new BuildingCardView{54 + (i * 84), 425, 80, 90, buildingCards.at(i), this};
        buildingPlace->setCoordinates(QVector<QPoint>{QPoint{29, 24}});
        buildingPlace->addCard(new CardView{":/images/images/cards/building/" + buildingCards.at(i)->getBuildingCard()->getImagePath() + ".jpg", 0, 0, 68});
        m_buildingCards.append(buildingPlace);
    }
}

void BoardView::initFoodMarkers() {
    m_foodMarkers.append(new FoodMarkerView{3, 512, 8, Team::RED, this});
    m_foodMarkers.append(new FoodMarkerView{10, 512, 8, Team::BLUE, this});
    m_foodMarkers.append(new FoodMarkerView{19, 512, 8, Team::GREEN, this});
    m_foodMarkers.append(new FoodMarkerView{28, 512, 8, Team::YELLOW, this});

    connect(m_game->getGameBoard()->getPlaces()->getField(), &FieldPlace::s_updateFarmerLevel, this, &BoardView::r_updateFarmerLevel);
}


// Getters
ForestView* BoardView::getForestView() const { return reinterpret_cast<ForestView*>(m_places[0]); }
ClayPitView* BoardView::getClayPitView() const { return reinterpret_cast<ClayPitView*>(m_places[1]); }
QuarryView* BoardView::getQuarryView() const { return reinterpret_cast<QuarryView*>(m_places[2]); }
RiverView* BoardView::getRiverView() const { return reinterpret_cast<RiverView*>(m_places[3]); }
FieldView* BoardView::getFieldView() const { return reinterpret_cast<FieldView*>(m_places[4]); }
ToolMakerView* BoardView::getToolMakerView() const { return reinterpret_cast<ToolMakerView*>(m_places[5]); }
HutView* BoardView::getHutView() const { return reinterpret_cast<HutView*>(m_places[6]); }
HuntView* BoardView::getHuntView() const { return reinterpret_cast<HuntView*>(m_places[7]); }
QVector<BuildingCardView*> BoardView::getBuildingCardViews() const { return m_buildingCards; }
QVector<CivilisationCardView*> BoardView::getCivilisationCardViews() const { return m_civilisationCards; }

void BoardView::moveFoodMarker(int level, Team team) {
    foreach(FoodMarkerView* foodMarker, m_foodMarkers) {
        if (foodMarker->getTeam() == team) {
            int xPos{int(foodMarker->pos().x())};
            foodMarker->setPos(xPos, (512 - (29*level))*SCALE);
            break;
        }
    }
}

void BoardView::updateAllFoodMarkers() {
    for (int i{0}; i < PLAYERS_IN_GAME; ++i) {
        Player* currenPlayer{m_game->getPlayers()->getPlayer(i)};
        int foodLevel{currenPlayer->getPlayerBoard()->getFoodTracker()->getFoodLevel()};
        Team team{currenPlayer->getTeam()};

        moveFoodMarker(foodLevel, team);
    }
}


// Slots
void BoardView::r_updateFarmerLevel(int level, Team team) {
    moveFoodMarker(level, team);
}
