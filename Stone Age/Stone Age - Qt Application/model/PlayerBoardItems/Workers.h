#ifndef WORKERS_H
#define WORKERS_H

#include <QVector>

#include "../Team.h"

class Worker;
class Food;
class ScoreTracker;
class FoodTracker;

class Workers {
    public:
        // Constructor
        Workers(Team team, int workersCapacity, Food* food, ScoreTracker* scoreTracker, FoodTracker* foodTracker);

        // Getters
        QVector<Worker*> getAvailableWorkers() const;
        int getWorkersCapacity() const;
        bool noWorkersAvailable(int amount = 1) const;
        bool areAllWorkersUsed() const;
        bool hasPlacedWorkerThisRound() const;

        // Setters
        void unsetPlacedWorkerThisRound();
        void setWorkerAmount(int amount);

        // Utils
        void increaseWorkersCapacity(int increaseBy = 1);
        void decreaseAvailableWorkers(int decreaseBy = 1);
        void increaseAvailableWorkers(int increaseBy = 1);
        void feed();


    private:
        Food* m_food;
        FoodTracker* m_foodTracker;
        ScoreTracker* m_scoreTracker;
        Team m_team;
        QVector<Worker*> m_availableWorkers;
        int m_workersCapacity;
        bool m_hasPlacedWorkerThisRound;
};

#endif // WORKERS_H
