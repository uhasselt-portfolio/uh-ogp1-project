#ifndef WORKERVIEW_H
#define WORKERVIEW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QString>

#include "../../model/Team.h"

class WorkerView : public QGraphicsPixmapItem {
    public:
        // Constructor
        WorkerView(QString path, int x, int y, QGraphicsScene *scene = nullptr, Team team = Team::RED);
        WorkerView(Team team, int x, int y, QGraphicsItem *parent = nullptr);
        WorkerView(Team team, int x, int y, int size = 18, QGraphicsItem *parent = nullptr);

        // Getters
        Team getTeam() const;

    private:
        Team m_team;
};

#endif // WORKERVIEW_H
