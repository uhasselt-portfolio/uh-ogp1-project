#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "PlaceView.h"

class Game;
class Place;


class FieldView : public PlaceView {
    public:
        // Constructor
        FieldView(int x, int y, int w, int h, QGraphicsItem *parent = nullptr, Game* game = nullptr, Place* place = nullptr);

        // Events
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // FIELDVIEW_H
