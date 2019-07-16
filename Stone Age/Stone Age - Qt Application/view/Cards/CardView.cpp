#include <QDebug>

#include "CardView.h"
#include "../../config.h"


// Constructor
CardView::CardView(QString path, int x, int y, int width, QGraphicsItem* parent) : QGraphicsPixmapItem{QPixmap{path}.scaledToWidth(width * SCALE)} {
    setPos(x, y);

    if (parent != nullptr)
        setParentItem(parent);
}

void CardView::moveCard(QGraphicsItem *to) {
    setParentItem(to);
}


// Events
void CardView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    (void)event;
}
