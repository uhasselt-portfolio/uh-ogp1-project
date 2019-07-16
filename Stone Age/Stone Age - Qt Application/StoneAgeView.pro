#-------------------------------------------------
#
# Project created by QtCreator 2019-04-25T19:24:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StoneAgeView
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    main.cpp \
    model/BuildingCardStack.cpp \
    model/CardStack.cpp \
    model/Cards/BuildingCard.cpp \
    model/Cards/CivilisationCard.cpp \
    model/Cards/CivilisationCardFooter.cpp \
    model/Cards/CivilisationCardHeader.cpp \
    model/Cards/RangedResourceBuildingCard.cpp \
    model/Cards/SelectedResourceBuildingCard.cpp \
    model/Cards/SpecificResourceBuildingCard.cpp \
    model/Dice.cpp \
    model/FileHandler.cpp \
    model/Game.cpp \
    model/GameBoard.cpp \
    model/GameRoundManager.cpp \
    model/Place.cpp \
    model/PlacedCards.cpp \
    model/Places.cpp \
    model/Places/BuildingCardPlace.cpp \
    model/Places/CivilisationCardPlace.cpp \
    model/Places/ClayPitPlace.cpp \
    model/Places/FieldPlace.cpp \
    model/Places/ForestPlace.cpp \
    model/Places/HuntPlace.cpp \
    model/Places/HutPlace.cpp \
    model/Places/QuarryPlace.cpp \
    model/Places/ResourcePlace.cpp \
    model/Places/RiverPlace.cpp \
    model/Places/ToolmakerPlace.cpp \
    model/Player.cpp \
    model/PlayerBoard.cpp \
    model/PlayerBoardItems/Food.cpp \
    model/PlayerBoardItems/FoodTracker.cpp \
    model/PlayerBoardItems/Resource.cpp \
    model/PlayerBoardItems/ScoreTracker.cpp \
    model/PlayerBoardItems/Tool.cpp \
    model/PlayerBoardItems/Tools.cpp \
    model/PlayerBoardItems/Worker.cpp \
    model/PlayerBoardItems/Workers.cpp \
    model/Players.cpp \
    model/Seeder.cpp \
    view/Cards/CardView.cpp \
    view/Components/GameButtonView.cpp \
    view/Components/GameMenuView.cpp \
    view/Components/GameTextView.cpp \
    view/EndGame/EndGameView.cpp \
    view/EndGame/PlayerStatsView.cpp \
    view/GameView.cpp \
    view/Items/DiceView.cpp \
    view/Items/FoodMarkerView.cpp \
    view/Items/ResourceView.cpp \
    view/Items/ToolView.cpp \
    view/Items/WorkerView.cpp \
    view/MainWindow.cpp \
    view/Places/BuildingCardView.cpp \
    view/Places/CivilisationCardView.cpp \
    view/Places/ClayPitView.cpp \
    view/Places/FieldView.cpp \
    view/Places/ForestView.cpp \
    view/Places/HuntView.cpp \
    view/Places/HutView.cpp \
    view/Places/PlaceView.cpp \
    view/Places/QuarryView.cpp \
    view/Places/RiverView.cpp \
    view/Places/ToolMakerView.cpp \
    view/PlayerBoards/PlayerBoardView.cpp \
    view/PlayerBoards/PlayerTextView.cpp \
    view/SideBoards/AnnounceView.cpp \
    view/SideBoards/BoardView.cpp \
    view/SideBoards/CardInventoryView.cpp \
    view/SideBoards/GameInfoView.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

HEADERS += \
    config.h \
    model/BuildingCardStack.h \
    model/CardStack.h \
    model/Cards/BuildingCard.h \
    model/Cards/CivilisationCard.h \
    model/Cards/CivilisationCardFooter.h \
    model/Cards/CivilisationCardHeader.h \
    model/Cards/RangedResourceBuildingCard.h \
    model/Cards/SelectedResourceBuildingCard.h \
    model/Cards/SpecificResourceBuildingCard.h \
    model/Dice.h \
    model/FileHandler.h \
    model/Game.h \
    model/GameBoard.h \
    model/GameRoundManager.h \
    model/Place.h \
    model/PlacedCards.h \
    model/Places.h \
    model/Places/BuildingCardPlace.h \
    model/Places/CivilisationCardPlace.h \
    model/Places/ClayPitPlace.h \
    model/Places/FieldPlace.h \
    model/Places/ForestPlace.h \
    model/Places/HuntPlace.h \
    model/Places/HutPlace.h \
    model/Places/QuarryPlace.h \
    model/Places/ResourcePlace.h \
    model/Places/RiverPlace.h \
    model/Places/ToolMakerPlace.h \
    model/Player.h \
    model/PlayerBoard.h \
    model/PlayerBoardItems/Food.h \
    model/PlayerBoardItems/FoodTracker.h \
    model/PlayerBoardItems/Resource.h \
    model/PlayerBoardItems/ScoreTracker.h \
    model/PlayerBoardItems/Tool.h \
    model/PlayerBoardItems/Tools.h \
    model/PlayerBoardItems/Worker.h \
    model/PlayerBoardItems/Workers.h \
    model/Players.h \
    model/Seeder.h \
    model/Team.h \
    view/Cards/CardView.h \
    view/Components/GameButtonView.h \
    view/Components/GameMenuView.h \
    view/Components/GameTextView.h \
    view/EndGame/EndGameView.h \
    view/EndGame/PlayerStatsView.h \
    view/GameView.h \
    view/Items/DiceView.h \
    view/Items/FoodMarkerView.h \
    view/Items/ResourceView.h \
    view/Items/ToolView.h \
    view/Items/WorkerView.h \
    view/MainWindow.h \
    view/Places/BuildingCardView.h \
    view/Places/CivilisationCardView.h \
    view/Places/ClayPitView.h \
    view/Places/FieldView.h \
    view/Places/ForestView.h \
    view/Places/HuntView.h \
    view/Places/HutView.h \
    view/Places/PlaceView.h \
    view/Places/QuarryView.h \
    view/Places/RiverView.h \
    view/Places/ToolMakerView.h \
    view/PlayerBoards/PlayerBoardView.h \
    view/PlayerBoards/PlayerTextView.h \
    view/SideBoards/AnnounceView.h \
    view/SideBoards/BoardView.h \
    view/SideBoards/CardInventoryView.h \
    view/SideBoards/GameInfoView.h

DISTFILES += \
    model/test.py
