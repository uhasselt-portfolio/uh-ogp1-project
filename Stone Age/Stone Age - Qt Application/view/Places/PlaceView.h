#ifndef PLACEVIEW_H
#define PLACEVIEW_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QVector>
#include <QPoint>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

#include "../../model/Team.h"

class Game;
class CardView;
class Place;
class CardView;
class WorkerView;

class PlaceView : public QObject, public QGraphicsRectItem {
    Q_OBJECT

    public:
        // Constructor
        PlaceView(int x, int y, int w, int h, QGraphicsItem *parent = nullptr, Game* game = nullptr, Place* place = nullptr);

        // Getters
        int getCoordinatesSize() const;
        int getItemsSize() const;

        int getX() const;
        int getY() const;
        int getW() const;
        int getH() const;

        // Setters
        void setCoordinates(QVector<QPoint> coordinates, bool parse = false);
        void genCoordinates(int amount);
        void addWorker(Team team);
        void addCard(CardView *card);

        // Utils
        void parseCoordinates();

        // Events
        virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) = 0;

    public slots:
        void r_addWorkerToView(Team team);
        void r_releasePlaceView(Team team);

    protected:
        Game* m_game;
        Place* m_place;
        QVector<QPoint> m_coordinates;
        QVector<QGraphicsPixmapItem *> m_items;
        CardView* m_cardView;

        QVector<WorkerView*> m_workers;
};

#endif // PLACEVIEW_H
