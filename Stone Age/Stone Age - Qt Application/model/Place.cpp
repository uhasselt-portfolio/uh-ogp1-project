#include <QDebug>

#include "Place.h"
#include "../config.h"
#include "PlayerBoardItems/Worker.h"
#include "PlayerBoardItems/Workers.h"
#include "Player.h"
#include "Game.h"
#include "PlayerBoard.h"
#include "Team.h"
#include "GameRoundManager.h"
#include "GameBoard.h"
#include "Places.h"
#include "Players.h"

// Constructor
Place::Place(QString name, int maximumWorkerAmount, Game* game) : m_game{game}, m_name{name}, m_maximumWorkerAmount{maximumWorkerAmount} {}


// Getters
int Place::getMaximumWorkerAmount() const {
    return m_maximumWorkerAmount;
}
QVector<Worker*> Place::getWorkers() const {
    return m_currentWorkers;
}
Worker* Place::getWorker(Team team) const {
    for(int i{0}; i < PLAYERS_IN_GAME; ++i) {
        if(m_currentWorkers.at(i)->getTeam() == team)
            return m_currentWorkers.at(i);
    }
    return nullptr;
}
bool Place::isFull() const {
    if(m_maximumWorkerAmount == INFINITE)
        return false;
    else
        return m_maximumWorkerAmount <= m_currentWorkers.size();
}


// Utils
void Place::releaseWorkers() {
    QVector<Team> teams{};
    teams.append(Team::RED);
    teams.append(Team::BLUE);
    teams.append(Team::GREEN);
    teams.append(Team::YELLOW);

    int currentWorkers = m_currentWorkers.size();

    if(currentWorkers > 0) {
        for(int i{0}; i < teams.size(); i++) {
            if(hasWorkers(teams.at(i)) > 0) {
                Player* player{m_game->getPlayers()->getPlayer(teams.at(i))};

                // Remove from model
                int workersRemoved{removeWorkers(teams.at(i))};
                player->getPlayerBoard()->getWorkers()->increaseAvailableWorkers(workersRemoved);

                // Update Player Board Visually
                player->getPlayerBoard()->updatePlayerBoard();

                // Update Place Visually
                emit s_releasePlaceView(teams.at(i));
            }
        }
    }
}

void Place::updateCalcView(Player *player, int toolLevel) {
    (void)player;
    (void)toolLevel;

    qDebug() << "@Place.cpp - updateCalcView called";
}

void Place::claimResources() {}
void Place::calculateMaterials(Player *player, int currentWorkers) {
    (void)player;
    (void)currentWorkers;
}

Player *Place::getPlayer() const {
    return nullptr;
}


// Called by the view
void Place::handleClickEvent(int amountOfWorkers) {
    // Push
    // TODO: Vind oplossing voor announce clear met card
    m_game->announce("");
    Places* places{m_game->getGameBoard()->getPlaces()};
    places->setLastClickedPlace(this);

    int gamePhase = m_game->getGameRoundManager()->getPhase();

    switch(gamePhase) {
        case 1:
            this->placeWorkers(amountOfWorkers);
            break;
        case 2:
            this->retrieveWorkers();
            break;
        default:
            qDebug() << "@ Place.cpp: 'unkown round' ...";
            break;
    }
}
void Place::placeWorkers(int amountOfWorkers) {
    if (isFull()) {
        emit s_announce("Hier is geen plaats meer.");
    }
    else {
        Player* currentPlayer{m_game->getPlayers()->getCurrentPlayer()};
        Team currentTeam{currentPlayer->getTeam()};
        Workers* playerWorkers{currentPlayer->getPlayerBoard()->getWorkers()};
        Places* places{m_game->getGameBoard()->getPlaces()};

        if (playerWorkers->noWorkersAvailable(amountOfWorkers)) {
            if (playerWorkers->noWorkersAvailable()) {
                emit s_announce("We gaan naar de volgende ronde, je hebt geen werkers meer.");
                m_game->getGameRoundManager()->nextGameRound();
            }
            else {
                emit s_announce("Je hebt niet genoeg werkers.");
            }
        }
        else {
            if (!places->isActivePlaceSet())
                places->setActivePlace(this);

            if(!m_game->getPlayers()->lastPlayerWithWorkers(currentPlayer->getTeam()) && !places->areEqual(this, places->getActivePlace()))
                emit s_announce("Je kan maar op 1 plaats werkers zetten per ronde.");
            else {
                for (int i{0}; i < amountOfWorkers; ++i) {
                    Worker* worker{new Worker{currentTeam}};

                    m_currentWorkers.append(worker);

                    playerWorkers->decreaseAvailableWorkers(1);

                    emit s_addWorkerToView(currentTeam);
                    m_game->getPlayers()->getCurrentPlayer()->getPlayerBoard()->updatePlayerBoard();
                    emit s_announce("");

                    if (isFull()) {
                        emit s_announce("We gaan naar de volgende ronde, deze plaats is vol.");
                        m_game->getGameRoundManager()->nextGameRound();
                    }
                }
            }
        }
    }
}
int Place::hasWorkers(Team team) const {
    int amountOfWorkers{0};

    for (int i{0}; i < m_currentWorkers.size(); ++i) {
        Team workerTeam{m_currentWorkers.at(i)->getTeam()};
        if(team == workerTeam)
            amountOfWorkers++;
    }
    return amountOfWorkers;
}

int Place::removeWorkers(Team team) {
    QVector<Worker*> remainingWorkers{};
    int amountOfWorkers{m_currentWorkers.size()};
    for(int i{0}; i < amountOfWorkers; ++i) {
        Team workerTeam{m_currentWorkers.at(i)->getTeam()};
        if(team != workerTeam) {
            remainingWorkers.append(m_currentWorkers.at(i));
        }
    }

    int removedWorkers = m_currentWorkers.size() - remainingWorkers.size();
    m_currentWorkers = remainingWorkers;

    return removedWorkers;
}
void Place::retrieveWorkers() {
    Player* currentPlayer{m_game->getPlayers()->getCurrentPlayer()};
    Team playerTeam{currentPlayer->getTeam()};
    Workers* playerWorkers{currentPlayer->getPlayerBoard()->getWorkers()};

    int amountOfWorkers{hasWorkers(playerTeam)};

    if(amountOfWorkers > 0) {

        calculateMaterials(currentPlayer, amountOfWorkers);

        // Modify the model
        int workersRemoved{removeWorkers(playerTeam)};
        playerWorkers->increaseAvailableWorkers(workersRemoved);

        // Update Player Board Visually
        currentPlayer->getPlayerBoard()->updatePlayerBoard();


        // Update Place Visually
        emit s_releasePlaceView(playerTeam);
    } else {
        emit s_announce("Deze plaats bevat geen werkers van jouw team!");
    }
}
