#include <QFont>

#include "PlayerTextView.h"
#include "../../config.h"

// Constructor
PlayerTextView::PlayerTextView(int x, int y, int padding, int fontSize, QString text, QGraphicsItem *parent) : QGraphicsTextItem{parent} {
    // Set default font
    QFont defaultFont{};
    defaultFont.setPixelSize(fontSize*SCALE);

    setFont(defaultFont);
    setPlainText(text);
    setPos((x + padding)*SCALE, (y + padding)*SCALE);
}
