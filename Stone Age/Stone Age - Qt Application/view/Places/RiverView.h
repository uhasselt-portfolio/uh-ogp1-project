#ifndef RIVERVIEW_H
#define RIVERVIEW_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "PlaceView.h"

class Game;
class Place;

class RiverView : public PlaceView {
    public:
        // Constructor
        RiverView(int x, int y, int w, int h, QGraphicsItem *parent = nullptr, Game* game = nullptr, Place* place = nullptr);

        // Events
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // RIVERVIEW_H
