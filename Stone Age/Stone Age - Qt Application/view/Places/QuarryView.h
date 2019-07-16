#ifndef QUARRYVIEW_H
#define QUARRYVIEW_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "PlaceView.h"

class Game;
class Place;

class QuarryView : public PlaceView {
    public:
        // Constructor
        QuarryView(int x, int y, int w, int h, QGraphicsItem *parent = nullptr, Game* game = nullptr, Place* place = nullptr);

        // Events
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // QUARRYVIEW_H
