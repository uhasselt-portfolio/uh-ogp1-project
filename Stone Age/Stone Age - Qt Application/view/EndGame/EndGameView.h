#ifndef ENDGAMEVIEW_H
#define ENDGAMEVIEW_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QString>

class Game;

class EndGameView : public QGraphicsRectItem {
    public:
        EndGameView(Game* game, QGraphicsScene *scene);

        // Utils
        void showScore();

    private:
        Game* m_game;
};

#endif // ENDGAMEVIEW_H
