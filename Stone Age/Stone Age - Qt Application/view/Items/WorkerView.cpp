#include "WorkerView.h"
#include "../../config.h"


// Constructors
WorkerView::WorkerView(QString path, int x, int y, QGraphicsScene *scene, Team team) : QGraphicsPixmapItem{QPixmap{path}.scaledToWidth(18 * SCALE)}, m_team{team} {
    setPos(x, y);

    if (scene != nullptr) {
        scene->addItem(this);
    }
}
WorkerView::WorkerView(Team team, int x, int y, QGraphicsItem *parent) : QGraphicsPixmapItem{}, m_team{team} {
    QString path{};
    switch (team) {
        case Team::RED:
            path = ":images/images/people/red.png";
            break;
        case Team::BLUE:
            path = ":images/images/people/blue.png";
            break;
        case Team::GREEN:
            path = ":images/images/people/green.png";
            break;
        case Team::YELLOW:
            path = ":images/images/people/yellow.png";
            break;
    }

    setPixmap(QPixmap{path}.scaledToWidth(18*SCALE));
    setPos(x*SCALE, y*SCALE);

    this->setParentItem(parent);
}
WorkerView::WorkerView(Team team, int x, int y, int size, QGraphicsItem *parent) : QGraphicsPixmapItem{}, m_team{team} {
    QString path{};
    switch (team) {
        case Team::RED:
            path = ":images/images/people/red.png";
            break;
        case Team::BLUE:
            path = ":images/images/people/blue.png";
            break;
        case Team::GREEN:
            path = ":images/images/people/green.png";
            break;
        case Team::YELLOW:
            path = ":images/images/people/yellow.png";
            break;
    }

    setPixmap(QPixmap{path}.scaledToWidth(size*SCALE));
    setPos(x*SCALE, y*SCALE);
    this->setParentItem(parent);
}


// Getters
Team WorkerView::getTeam() const {
    return m_team;
}

