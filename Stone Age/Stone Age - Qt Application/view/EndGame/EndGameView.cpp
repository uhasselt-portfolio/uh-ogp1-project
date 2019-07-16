#include <QGraphicsTextItem>

#include "EndGameView.h"
#include "../../config.h"

#include "../../model/Game.h"
#include "../../model/Players.h"
#include "../../model/Player.h"
#include "../../model/PlayerBoard.h"
#include "../../model/PlayerBoardItems/ScoreTracker.h"

EndGameView::EndGameView(Game *game, QGraphicsScene *scene) : m_game{game} {
    setRect(0, 0, 1400*SCALE, 828*SCALE);
    setPos(0, 0);

    // Background
    QGraphicsPixmapItem* bg{new QGraphicsPixmapItem{QPixmap{":/images/images/menubg.jpg"}.scaled(1400*SCALE, 828*SCALE)}};
    bg->setPos(0, 0);
    bg->setOpacity(0.6);
    bg->setParentItem(this);

    // Title
    QGraphicsTextItem* stoneAge{new QGraphicsTextItem{"Game is afgelopen!", this}};
    QFont title{};
    title.setPixelSize(50*SCALE);
    stoneAge->setFont(title);
    stoneAge->setPos(30*SCALE, 20*SCALE);

    // Adding item to scene
    if (scene != nullptr)
        scene->addItem(this);

    hide();
}

void EndGameView::showScore() {
    for(int i{0}; i < PLAYERS_IN_GAME; ++i) {
        Player* currentPlayer{m_game->getPlayers()->getPlayer(i)};
        PlayerBoard* playerBoard{currentPlayer->getPlayerBoard()};
        int currentScore{playerBoard->getCivlisationCardScore() + playerBoard->getScoreTracker()->getScore()};

        QGraphicsTextItem* text{new QGraphicsTextItem{currentPlayer->getName() + "'s punten: " + QString::number(currentScore), this}};
        QFont styling{};
        styling.setPixelSize(25 * SCALE);
        text->setFont(styling);
        text->setPos(30*SCALE, (100 + (40*i))*SCALE);
    }
}
