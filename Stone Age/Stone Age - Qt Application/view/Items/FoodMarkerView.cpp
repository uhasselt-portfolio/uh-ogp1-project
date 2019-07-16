#include "FoodMarkerView.h"
#include "../../config.h"

FoodMarkerView::FoodMarkerView(int x, int y, int size, Team team, QGraphicsItem *parent) : QGraphicsPixmapItem{parent}, m_team{team} {
    setPos(x*SCALE, y*SCALE);

    QString path{};
    switch(team) {
        case Team::RED:
            path = ":/images/images/foodmarker/red.gif"; break;
        case Team::BLUE:
            path = ":/images/images/foodmarker/blue.gif"; break;
        case Team::YELLOW:
            path = ":/images/images/foodmarker/yellow.gif"; break;
        case Team::GREEN:
            path = ":/images/images/foodmarker/green.gif"; break;
    }

    setPixmap(QPixmap{path}.scaledToWidth(size*SCALE));
}

Team FoodMarkerView::getTeam() const {
    return m_team;
}
