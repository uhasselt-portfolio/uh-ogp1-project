#ifndef CARDVIEW_H
#define CARDVIEW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QString>

class CardView : public QGraphicsPixmapItem {
    public:
        // Constructor
        CardView(QString path, int x, int y, int width = 200, QGraphicsItem* parent=nullptr);

        // Visuals
        void moveCard(QGraphicsItem* to);

        // Events
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CARDVIEW_H
