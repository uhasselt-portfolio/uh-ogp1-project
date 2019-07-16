#ifndef WORKER_H
#define WORKER_H

#include "../Team.h"

class Worker {
    public:
        // Constructor
        Worker(Team team);

        // Getters
        Team getTeam() const;

    private:
        Team m_team;
};

#endif // WORKER_H
