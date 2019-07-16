#ifndef HUNTVIEW_H
#define HUNTVIEW_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "PlaceView.h"

class Game;
class Place;

class HuntView : public PlaceView {
    public:
        // Constructor
        HuntView(int x, int y, int w, int h, QGraphicsItem *parent = nullptr, Game* game = nullptr, Place* place = nullptr);

        // Events
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // HUNTVIEW_H
