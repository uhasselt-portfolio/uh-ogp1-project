#ifndef GAMETEXTVIEW_H
#define GAMETEXTVIEW_H

#include <QGraphicsTextItem>
#include "../../config.h"

class GameTextView : public QGraphicsTextItem{
    public:
        // Constructor
        GameTextView(int x, int y, int fontSize = 16, QString text = "", QGraphicsItem* parent = nullptr);
};

#endif // GAMETEXTVIEW_H
