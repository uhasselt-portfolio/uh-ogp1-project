#ifndef TOOLVIEW_H
#define TOOLVIEW_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class Game;

class ToolView : QGraphicsPixmapItem {
    public:
        // Constructor
        ToolView(int x=0, int y=0, int size=20, int level=1, QGraphicsItem *parent=nullptr, bool selectable = false, Game* game=nullptr);

        // Setters (visuals)
        void setInactive();

        // Events
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    private:
        Game* m_game;
        int m_level;
};

#endif // TOOLVIEW_H
