#ifndef TOOLMAKERVIEW_H
#define TOOLMAKERVIEW_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "PlaceView.h"

class Game;
class Place;

class ToolMakerView : public PlaceView {
    public:
        // Constructor
        ToolMakerView(int x, int y, int w, int h, QGraphicsItem *parent = nullptr, Game* game = nullptr, Place* place = nullptr);

        // Events
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // TOOLMAKERVIEW_H
