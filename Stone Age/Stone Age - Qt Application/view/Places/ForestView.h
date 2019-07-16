#ifndef FORESTVIEW_H
#define FORESTVIEW_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "PlaceView.h"

class Game;
class Place;

class ForestView : public PlaceView {
    public:
        // Constructor
        ForestView(int x, int y, int w, int h, QGraphicsItem *parent = nullptr, Game* game = nullptr, Place* place = nullptr);

        // Events
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // FORESTVIEW_H
