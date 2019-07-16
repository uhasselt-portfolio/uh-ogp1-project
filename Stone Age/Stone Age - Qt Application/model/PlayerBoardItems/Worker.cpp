#include "Worker.h"

Worker::Worker(Team team) : m_team{team} {

}

Team Worker::getTeam() const {
    return m_team;
}
