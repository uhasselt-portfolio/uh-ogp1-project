#include "GameTextView.h"

#include <QFont>

// Constructor
GameTextView::GameTextView(int x, int y, int fontSize, QString text, QGraphicsItem *parent) : QGraphicsTextItem{} {
    setPos(x*SCALE, y*SCALE);

    QFont font{};
    font.setPixelSize(fontSize*SCALE);
    setPlainText(text);

    setParentItem(parent);
}
