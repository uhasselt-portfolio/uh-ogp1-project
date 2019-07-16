#ifndef FOODMARKERVIEW_H
#define FOODMARKERVIEW_H

#include <QGraphicsPixmapItem>

#include "../../model/Team.h"

class FoodMarkerView : public QGraphicsPixmapItem {
    public:
        // Constructor
        FoodMarkerView(int x, int y, int size, Team team, QGraphicsItem *parent=nullptr);

        // Getters
        Team getTeam() const;

    private:
        Team m_team;
};

#endif // FOODMARKERVIEW_H
