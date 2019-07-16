#ifndef CLAYPITVIEW_H
#define CLAYPITVIEW_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "PlaceView.h"

class ClayPitView: public PlaceView {
    public:
        // Constructor
        ClayPitView(int x, int y, int w, int h, QGraphicsItem *parent = nullptr, Game* game = nullptr, Place* place = nullptr);

        // Events
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CLAYPITVIEW_H
