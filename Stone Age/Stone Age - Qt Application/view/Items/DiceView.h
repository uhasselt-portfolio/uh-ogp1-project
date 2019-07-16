#ifndef DICEVIEW_H
#define DICEVIEW_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class DiceView : public QGraphicsPixmapItem {
    public:
        // Constructor
        DiceView(int x=0, int y=0, int size=20, int amount=1, QGraphicsItem *parent=nullptr);
};

#endif // DICEVIEW_H
