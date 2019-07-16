#include <QPen>
#include <QRandomGenerator>
#include <QDebug>

#include "PlaceView.h"
#include "../../config.h"

#include "../Cards/CardView.h"
#include "../Items/WorkerView.h"

#include "../../model/Game.h"
#include "../../model/Place.h"
#include "../Cards/CardView.h"

// Constructor
PlaceView::PlaceView(int x, int y, int w, int h, QGraphicsItem *parent, Game* game, Place* place) : QGraphicsRectItem{}, m_game{game}, m_place{place} {
    QPen pen{};
    pen.setWidth(4);
    setPen(HIDE_BORDER ? Qt::NoPen : pen);

    setRect(0, 0, w*SCALE, h*SCALE);
    setPos(x*SCALE, y*SCALE);

    setFlag(ItemIsSelectable);

    setParentItem(parent);
//    parent
//    scene->addItem(this);
}


// Getters
int PlaceView::getCoordinatesSize() const {
    return m_coordinates.size();
}
int PlaceView::getItemsSize() const {
    return m_workers.size();
}
int PlaceView::getX() const {
    return int(pos().x() / SCALE);
}
int PlaceView::getY() const {
    return int(pos().y() / SCALE);
}
int PlaceView::getW() const {
    return int(boundingRect().width() / SCALE);
}
int PlaceView::getH() const {
    return int(boundingRect().height() / SCALE);
}


// Setters
void PlaceView::setCoordinates(QVector<QPoint> coordinates, bool parse) {
    m_coordinates = coordinates;

    if (parse)
        parseCoordinates();
}
void PlaceView::genCoordinates(int amount) {
    int x{getX()}, y{getY()}, w{getW()}, h{getH()}, workersSize{18*SCALE};

    for(int i{0}; i < amount; ++i) {
        QRandomGenerator randX{quint32(amount * i / 2)}, randY{quint32(amount * i * 2)};

        QPoint newPos{randX.bounded(w - workersSize) + x, randY.bounded(h - workersSize) + y};
        m_coordinates.append(newPos);
    }

    parseCoordinates();
}
void PlaceView::addWorker(Team team) {
    // ask ingo cause cords still contain worker after deleted
    QPoint pos{m_coordinates[getItemsSize()]};

    WorkerView* worker{new WorkerView{team, pos.x(), pos.y(), this}};
    m_workers.append(worker);

}
void PlaceView::addCard(CardView *card) {
    card->setParentItem(this);
    card->setPos(5*SCALE, 5*SCALE);
    m_cardView = card;
}


// Utils
void PlaceView::parseCoordinates() {
    for(int i{0}, l{m_coordinates.size()}; i < l; ++i) {
        int xCoord{int(pos().x() / SCALE)};
        int yCoord{int(pos().y() / SCALE)};

        m_coordinates[i] = QPoint{m_coordinates[i].x() - xCoord, m_coordinates[i].y() - yCoord};
    }
}


// Slots
void PlaceView::r_addWorkerToView(Team team) {
    addWorker(team);
}
void PlaceView::r_releasePlaceView(Team team) {
    QVector<WorkerView*> newWorkers{};
    for (int i{0}, l{m_workers.size()}; i < l; ++i) {
        if (m_workers[i]->getTeam() == team) {
            m_workers[i]->hide();
        }
        else {
            newWorkers.append(m_workers[i]);
        }
    }

    m_workers = newWorkers;
}
