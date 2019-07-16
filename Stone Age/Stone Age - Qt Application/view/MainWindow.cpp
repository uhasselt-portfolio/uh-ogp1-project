#include "MainWindow.h"
#include "../config.h"

#include <QObject>
#include <QString>
#include <QDebug>
#include <QGraphicsView>
#include <QHBoxLayout>

#include "../model/Game.h"

#include "GameView.h"
#include "Components/GameButtonView.h"
#include "Components/GameMenuView.h"
#include "../model/FileHandler.h"

// Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Init board, start_button, quit_button, ...
    Game* game = new Game();
//    FileHandler* fileH{new FileHandler{game}};
//    fileH->importJson();


    GameView* gameView{new GameView{this, game}};

    GameButtonView* startBtn{gameView->getGameMenu()->getStartBtn()};
    GameButtonView* quitBtn{gameView->getGameMenu()->getQuitBtn()};
    GameButtonView* saveBtn{gameView->getGameMenu()->getSaveBtn()};
    GameButtonView* loadBtn{gameView->getGameMenu()->getLoadBtn()};

    // Signals
    connect(startBtn, &GameButtonView::s_buttonClicked, gameView, &GameView::r_renderGameBoard);
    connect(quitBtn, &GameButtonView::s_buttonClicked, this, &QWidget::close);
    connect(saveBtn, &GameButtonView::s_buttonClicked, game, &Game::r_save);

    connect(loadBtn, &GameButtonView::s_buttonClicked, game, &Game::r_load);
    connect(loadBtn, &GameButtonView::s_buttonClicked, gameView, &GameView::r_renderGameBoard);

    // Init view
    QGraphicsView *view = new QGraphicsView{gameView, this};

//    view->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setCentralWidget(view);
    view->setFixedSize(1400 * SCALE, 828 * SCALE);
}



