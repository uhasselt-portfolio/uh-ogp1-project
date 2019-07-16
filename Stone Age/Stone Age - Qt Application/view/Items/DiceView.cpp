#include "DiceView.h"
#include "../../config.h"

DiceView::DiceView(int x, int y, int size, int amount, QGraphicsItem *parent) : QGraphicsPixmapItem{parent} {
    setPos(x*SCALE, y*SCALE);
    setPixmap(QPixmap{":/images/images/dice/"+ QString::number(amount) +".gif"}.scaledToWidth(size*SCALE));
}
