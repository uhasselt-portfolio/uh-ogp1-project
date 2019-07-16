#ifndef PLACE_H
#define PLACE_H

#include <QVector>
#include <QString>
#include <QObject>

#include "Team.h"

class Worker;
class Player;
class Game;
class PlayerBoard;

class Place : public QObject {
    Q_OBJECT
    public:
        // Constructor
        Place(QString name, int maximumWorkerAmount, Game* game);

        // Getters
        int getMaximumWorkerAmount() const;
        QVector<Worker*> getWorkers() const;
        Worker* getWorker(Team team) const;
        bool isFull() const;
        int hasWorkers(Team team) const;

        // Setters
        void handleClickEvent(int amountOfWorkers = 1);
        void placeWorkers(int amountOfWorkers = 1);
        void retrieveWorkers();

        // Utils
        void releaseWorkers();
        virtual void calculateMaterials(Player* player, int currentWorkers);
        virtual void updateCalcView(Player* player, int toolLevel);
        virtual void claimResources();
        virtual Player* getPlayer() const;

    signals:
        void s_addWorkerToView(Team team);
        void s_announce(QString text);
        void s_releasePlaceView(Team team);
        void s_updateFarmerLevel(int level, Team team);

    protected:
        Game* m_game;
        QVector<Worker*> m_currentWorkers;

    private:
        QString m_name;
        int m_maximumWorkerAmount;

        int removeWorkers(Team team);
};

#endif // PLACE_H
