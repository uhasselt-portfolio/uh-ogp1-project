#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QColor>

#include "GameView.h"
#include "../config.h"
#include "../model/Game.h"
#include "../model/PlayerBoard.h"
#include "../model/Player.h"

#include "Components/GameMenuView.h"
#include "Components/GameButtonView.h"
#include "SideBoards/BoardView.h"
#include "SideBoards/AnnounceView.h"
#include "SideBoards/CardInventoryView.h"
#include "PlayerBoards/PlayerBoardView.h"

#include "../model/Places/ForestPlace.h"
#include "../model/Places/ClayPitPlace.h"
#include "../model/Places/QuarryPlace.h"
#include "../model/Places/RiverPlace.h"
#include "../model/Places/FieldPlace.h"
#include "../model/Places/ToolMakerPlace.h"
#include "../model/Places/HutPlace.h"
#include "../model/Places/HuntPlace.h"

#include "Places/ForestView.h"
#include "Places/ClayPitView.h"
#include "Places/QuarryView.h"
#include "Places/RiverView.h"
#include "Places/FieldView.h"
#include "Places/ToolMakerView.h"
#include "Places/HutView.h"
#include "Places/HuntView.h"
#include "Places/CivilisationCardView.h"
#include "Places/BuildingCardView.h"
#include "Places/CivilisationCardView.h"
#include "Cards/CardView.h"
#include "EndGame/EndGameView.h"

#include "../model/Player.h"
#include "../model/Players.h"
#include "../model/Places.h"
#include "../model/GameBoard.h"
#include "../model/GameRoundManager.h"

#include "../model/PlacedCards.h"
#include "../model/Places/BuildingCardPlace.h"
#include "../model/Places/CivilisationCardPlace.h"


// Constructor
GameView::GameView(QObject *parent, Game* game) :
    QGraphicsScene{parent}, m_game{game}, m_gameBoard{nullptr}, m_announceView{nullptr}, m_playerBoards{}, m_gameMenu{nullptr}, m_buildingView{nullptr}, m_civilView{nullptr}, m_gameInfoView{nullptr} {
    // Create game menu
    initGameMenu();
}


// Init
void GameView::initAnnounceBar() {
    m_announceView = new AnnounceView{0, 0, 800, 67, this, m_game};
    m_announceView->announceBig("Welcome to Stone Age!");

    // Handle connections ...
    GameButtonView* nextBtn{m_announceView->getNextBtn()};
    connect(nextBtn, &GameButtonView::s_buttonClicked, this, &GameView::r_updateRound);
    connect(m_announceView->getPayBtn(), &GameButtonView::s_buttonClicked, m_announceView, &AnnounceView::r_payResources);

    connect(m_game, &Game::s_announce, m_announceView, &AnnounceView::r_announceSmall);
    connect(m_game, &Game::s_announceResources, m_announceView, &AnnounceView::r_announceResources);
}
void GameView::initGameBoard() {
    m_gameBoard = new BoardView{0, 67, 528, this, m_game};
}
void GameView::initPlayerBoards() {
    for(int i{0}; i < PLAYERS_IN_GAME; ++i) {
        QVector<Team> teams{Team::RED, Team::BLUE, Team::GREEN, Team::YELLOW};

        // Connect playerboards
        Player* currentPlayer{m_game->getPlayers()->getPlayer(i)};
        PlayerBoard* playerBoard{currentPlayer->getPlayerBoard()};
        PlayerBoardView *playerBoardView = new PlayerBoardView{805, 150*i, 295, 145, this, m_game, teams[i]};
        if (i == 0) playerBoardView->setActive(true);

        connect(playerBoard, &PlayerBoard::s_updatePlayerBoard, playerBoardView, &PlayerBoardView::r_renderPlayerBoard);
        connect(playerBoard, &PlayerBoard::s_setActiveState, playerBoardView, &PlayerBoardView::r_setActiveState);

        // Create string
        QString playerString{"Player: " + currentPlayer->getName()};
        playerBoardView->setName(playerString); // TODO: move to constructor
        playerBoardView->setScore("Score: 0");

        m_playerBoards.append(playerBoardView);
    }

}
void GameView::initCivilisationCards() {
    m_civilView = new CardInventoryView{550, 600, 550, 228, this};

    QFont font{};
    font.setPixelSize(12*SCALE);
    (new QGraphicsTextItem{"Civilisation Cards", m_civilView})->setFont(font);

    for(int i{0}; i < CARD_AMOUNT_ON_BOARD; ++i) {
        CivilisationCardPlace* civilisationCardPlace{m_game->getGameBoard()->getPlacedCards()->getPlacedCivilisationCards().at(i)};
        CivilisationCardView* civilisationCardView{this->getGameBoard()->getCivilisationCardViews().at(i)};

        connect(civilisationCardPlace, &CivilisationCardPlace::s_addWorkerToView, civilisationCardView, &CivilisationCardView::r_addWorkerToView);
        connect(civilisationCardPlace, &CivilisationCardPlace::s_releasePlaceView, civilisationCardView, &CivilisationCardView::r_releasePlaceView);
        connect(civilisationCardPlace, &CivilisationCardPlace::s_removeCivlisationCardView, civilisationCardView, &CivilisationCardView::r_removeCivilisationCardView);
        connect(civilisationCardPlace, &CivilisationCardPlace::s_addCivilisationCardView, civilisationCardView, &CivilisationCardView::r_addCivilisationCardView);
        connect(civilisationCardPlace, &CivilisationCardPlace::s_announcePayResources, m_announceView, &AnnounceView::r_announcePayResources);
    }

    m_civilView->setBrush(QBrush{QColor{165, 141, 112}});
}
void GameView::initBuildingCards() {
    m_buildingView = new CardInventoryView{0, 600, 550, 228, this};

    QFont font{};
    font.setPixelSize(12*SCALE);
    (new QGraphicsTextItem{"Building Cards", m_buildingView})->setFont(font);


    for(int i{0}; i < CARD_AMOUNT_ON_BOARD; ++i) {
        BuildingCardPlace* buildingCardPlace{m_game->getGameBoard()->getPlacedCards()->getPlacedBuildingCards().at(i)};
        BuildingCardView *buildingCardView{this->getGameBoard()->getBuildingCardViews().at(i)};

        connect(buildingCardPlace, &BuildingCardPlace::s_addWorkerToView, buildingCardView, &BuildingCardView::r_addWorkerToView);
        connect(buildingCardPlace, &BuildingCardPlace::s_releasePlaceView, buildingCardView, &BuildingCardView::r_releasePlaceView);
        connect(buildingCardPlace, &BuildingCardPlace::s_removeBuildingCardView, buildingCardView, &BuildingCardView::r_removeBuildingCardView);
        connect(buildingCardPlace, &BuildingCardPlace::s_addBuildingCardView, buildingCardView, &BuildingCardView::r_addBuildingCardView);
        connect(buildingCardPlace, &BuildingCardPlace::s_announcePayResources, m_announceView, &AnnounceView::r_announcePayResources);
    }
}

void GameView::initGameInfo() {
    m_gameInfoView = new QGraphicsRectItem{0, 0, 295 * SCALE, 595*SCALE};
    m_gameInfoView->setPos(1105*SCALE, 0);
    m_gameInfoView->setPen(Qt::NoPen);
    m_gameInfoView->setBrush(QBrush{QColor{165, 159, 152}});

    GameButtonView* menuBtn{new GameButtonView{20, 20, "Menu", m_gameInfoView}};
    menuBtn->setPen(QPen{QBrush{QColor{0, 0, 0}}, 1});

    connect(menuBtn, &GameButtonView::s_buttonClicked, this, &GameView::r_toggleMenu);


    QFont font{};
    font.setPixelSize(12*SCALE);
    (new QGraphicsTextItem{"GameInfoView", m_gameInfoView})->setFont(font);

    addItem(m_gameInfoView);
}

void GameView::initEndGameScreen() {
    m_endGame = new EndGameView{m_game, this};

    GameRoundManager* grm{m_game->getGameRoundManager()};
    connect(grm, &GameRoundManager::s_endGame, this, &GameView::r_endGame);
}

void GameView::initGameMenu() {
    m_gameMenu = new GameMenuView{0, 0, 1400, 828, this};
}

// Getters
GameMenuView* GameView::getGameMenu() const {
    return m_gameMenu;
}
BoardView* GameView::getGameBoard() const {
    return m_gameBoard;
}
PlayerBoardView* GameView::getPlayerBoard(int index) const {
    if (m_playerBoards.size() > index)
        return m_playerBoards[index];
    return nullptr;
}


// Utils
void GameView::hideGameMenu() {
    m_gameMenu->hide();
}

void GameView::connectAll() {
    // CONNECTS
    ForestPlace* forest{m_game->getGameBoard()->getPlaces()->getForest()};
    ForestView* forestView{this->getGameBoard()->getForestView()};
    connect(forest, &ForestPlace::s_addWorkerToView, forestView, &ForestView::r_addWorkerToView);
    connect(forest, &ForestPlace::s_releasePlaceView, forestView, &ForestView::r_releasePlaceView);
    connect(forest, &ForestPlace::s_announce, m_announceView, &AnnounceView::r_announceSmall);

    ClayPitPlace* clayPit{m_game->getGameBoard()->getPlaces()->getClayPit()};
    ClayPitView* clayPitView{this->getGameBoard()->getClayPitView()};
    connect(clayPit, &ClayPitPlace::s_addWorkerToView, clayPitView, &ClayPitView::r_addWorkerToView);
    connect(clayPit, &ClayPitPlace::s_releasePlaceView, clayPitView, &ClayPitView::r_releasePlaceView);
    connect(clayPit, &ClayPitPlace::s_announce, m_announceView, &AnnounceView::r_announceSmall);

    QuarryPlace* quarry{m_game->getGameBoard()->getPlaces()->getQuarry()};
    QuarryView* quarryView{this->getGameBoard()->getQuarryView()};
    connect(quarry, &QuarryPlace::s_addWorkerToView, quarryView, &QuarryView::r_addWorkerToView);
    connect(quarry, &QuarryPlace::s_releasePlaceView, quarryView, &QuarryView::r_releasePlaceView);
    connect(quarry, &QuarryPlace::s_announce, m_announceView, &AnnounceView::r_announceSmall);

    RiverPlace* river{m_game->getGameBoard()->getPlaces()->getRiver()};
    RiverView* riverView{this->getGameBoard()->getRiverView()};
    connect(river, &RiverPlace::s_addWorkerToView, riverView, &RiverView::r_addWorkerToView);
    connect(river, &RiverPlace::s_releasePlaceView, riverView, &RiverView::r_releasePlaceView);
    connect(river, &RiverPlace::s_announce, m_announceView, &AnnounceView::r_announceSmall);

    FieldPlace* field{m_game->getGameBoard()->getPlaces()->getField()};
    FieldView* fieldView{this->getGameBoard()->getFieldView()};
    connect(field, &FieldPlace::s_addWorkerToView, fieldView, &FieldView::r_addWorkerToView);
    connect(field, &FieldPlace::s_releasePlaceView, fieldView, &FieldView::r_releasePlaceView);
    connect(field, &FieldPlace::s_announce, m_announceView, &AnnounceView::r_announceSmall);

    ToolMakerPlace* toolMaker{m_game->getGameBoard()->getPlaces()->getToolMaker()};
    ToolMakerView* toolMakerView{this->getGameBoard()->getToolMakerView()};
    connect(toolMaker, &ToolMakerPlace::s_addWorkerToView, toolMakerView, &ToolMakerView::r_addWorkerToView);
    connect(toolMaker, &ToolMakerPlace::s_releasePlaceView, toolMakerView, &ToolMakerView::r_releasePlaceView);
    connect(toolMaker, &ToolMakerPlace::s_announce, m_announceView, &AnnounceView::r_announceSmall);

    HutPlace* hut{m_game->getGameBoard()->getPlaces()->getHut()};
    HutView* hutView{this->getGameBoard()->getHutView()};
    connect(hut, &HutPlace::s_addWorkerToView, hutView, &HutView::r_addWorkerToView);
    connect(hut, &HutPlace::s_releasePlaceView, hutView, &HutView::r_releasePlaceView);
    connect(hut, &HutPlace::s_announce, m_announceView, &AnnounceView::r_announceSmall);

    HuntPlace* hunt{m_game->getGameBoard()->getPlaces()->getHunt()};
    HuntView* huntView{this->getGameBoard()->getHuntView()};
    connect(hunt, &HuntPlace::s_addWorkerToView, huntView, &HuntView::r_addWorkerToView);
    connect(hunt, &HuntPlace::s_releasePlaceView, huntView, &HuntView::r_releasePlaceView);
    connect(hunt, &HuntPlace::s_announce, m_announceView, &AnnounceView::r_announceSmall);

    // Connect Player - Building Card Inventory
    Players* players{m_game->getPlayers()};
    connect(players, &Players::s_updateBuildingInventory, m_buildingView, &CardInventoryView::r_updateBuildingInventory);
    connect(players, &Players::s_updateCivilisationInventory, m_civilView, &CardInventoryView::r_updateCivilisationInventory);

}


// Slots
void GameView::r_renderGameBoard() {
    if (m_gameBoard == nullptr) {
        hideGameMenu();
        initAnnounceBar();
        initGameBoard();
        initPlayerBoards();
        initCivilisationCards();
        initBuildingCards();
        initGameInfo();

        initEndGameScreen();

        // Update all player boards with actual data from seeder
        connectAll();
        m_game->updateAllPlayerBoards();
        m_gameBoard->updateAllFoodMarkers();


        m_gameMenu->getStartBtn()->setBtnText("Resume", m_gameMenu);
        m_gameMenu->gameStarted();

        m_endGame->hide();
    }
    else {
        m_gameMenu->hide();

        m_announceView->show();
        m_gameBoard->show();
        m_gameInfoView->show();
        m_civilView->show();
        m_buildingView->show();
        foreach(PlayerBoardView* playerBoardView, m_playerBoards) { playerBoardView->show(); }
    }
}
void GameView::r_updateRound() {
    qDebug() << "@GameView - Next buttton click recieved...";
    m_game->announce("");
    m_game->getGameRoundManager()->nextGameRound();
}

void GameView::r_toggleMenu() {
    m_announceView->hide();
    m_gameBoard->hide();
    m_gameInfoView->hide();
    m_civilView->hide();
    m_buildingView->hide();
    foreach(PlayerBoardView* playerBoardView, m_playerBoards) { playerBoardView->hide(); }
    m_endGame->hide();
    m_gameMenu->show();
}

void GameView::r_endGame() {
    m_announceView->hide();
    m_gameBoard->hide();
    m_gameInfoView->hide();
    m_civilView->hide();
    m_buildingView->hide();
    foreach(PlayerBoardView* playerBoardView, m_playerBoards) { playerBoardView->hide(); }
    m_gameMenu->hide();

    m_endGame->show();
    m_endGame->showScore();
}
