#include <QDebug>

#include "Workers.h"
#include "../../config.h"
#include "Worker.h"
#include "../PlayerBoard.h"
#include "FoodTracker.h"
#include "ScoreTracker.h"
#include "Food.h"

// Constructor
Workers::Workers(Team team, int workersCapacity, Food* food, ScoreTracker* scoreTracker, FoodTracker* foodTracker)
    : m_food{food},  m_team{team},  m_workersCapacity{workersCapacity},  m_scoreTracker{scoreTracker}, m_foodTracker{foodTracker}, m_hasPlacedWorkerThisRound{false} {
    for(int i = 0; i < m_workersCapacity; i++) {
        Worker* worker{new Worker{m_team}};
        m_availableWorkers.append(worker);
    }
}


// Getters
QVector<Worker*> Workers::getAvailableWorkers() const {
    return m_availableWorkers;
}
int Workers::getWorkersCapacity() const {
    return m_workersCapacity;
}
bool Workers::noWorkersAvailable(int amount) const {
    return m_availableWorkers.size() < amount;
}
bool Workers::areAllWorkersUsed() const {
    for(int i{0}; i < m_availableWorkers.size(); ++i) {
        if(getAvailableWorkers().size() > 0) {
            return false;
        }
    }
    return true;
}
bool Workers::hasPlacedWorkerThisRound() const {
    return m_hasPlacedWorkerThisRound;
}

// Setters
void Workers::unsetPlacedWorkerThisRound() {
    m_hasPlacedWorkerThisRound = false;
}

void Workers::setWorkerAmount(int amount) {
    m_workersCapacity = amount;
}

// Utils
void Workers::increaseAvailableWorkers(int increaseBy) {
    for(int i = 0; i < increaseBy; i++) {
        if(m_workersCapacity >= m_availableWorkers.count()) {
            Worker* worker{new Worker{m_team}};
            m_availableWorkers.append(worker);
        }
    }
}
void Workers::increaseWorkersCapacity(int increaseBy) {
    if(m_workersCapacity <= MAXIMUM_WORKERS_CAPACITY) {
        m_workersCapacity += increaseBy;
        increaseAvailableWorkers();
    }

}
void Workers::decreaseAvailableWorkers(int decreaseBy) {
    if(decreaseBy > 0)
        m_hasPlacedWorkerThisRound = true;

    for(int i = 0; i < decreaseBy; i++) {
        if(m_availableWorkers.count() >= 1) {
            m_availableWorkers.removeLast();
        }
    }
}
void Workers::feed() {
    // Increase by farmer level
    int foodLevel{m_foodTracker->getFoodLevel()};
    m_food->increaseFoodSupply(foodLevel);

    // Feed people
    int availableFood{m_food->getFoodSupply()};

    m_food->decreaseFoodSupply(m_workersCapacity);
    if (availableFood < m_workersCapacity)
        m_scoreTracker->decreaseScore(10);
}

