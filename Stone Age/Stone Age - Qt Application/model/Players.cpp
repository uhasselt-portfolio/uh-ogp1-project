#include <QDebug>
#include <QVector>

#include "Players.h"
#include "../config.h"
#include "Game.h"
#include "GameRoundManager.h"
#include "Player.h"
#include "PlayerBoard.h"
#include "PlayerBoardItems/Workers.h"
#include "Cards/BuildingCard.h"
#include "Cards/CivilisationCard.h"

#include "FileHandler.h"

// Constructor
Players::Players(QVector<Player*> players, Game* game) : m_players{players}, m_game{game} {}

// Getters
Player* Players::getPlayer(int playerIndex) const {
    if(playerIndex >= 0 && playerIndex < PLAYERS_IN_GAME) {
        return m_players[playerIndex];
    }
    return nullptr;
}

Player* Players::getPlayer(Team team) const {
    for(int i{0}; i < m_players.size(); ++i) {
        if(m_players.at(i)->getTeam() == team) {
            return m_players.at(i);
        }
    }
    return nullptr;
}

Player* Players::getCurrentPlayer() const  {
    // Round starts at 1, array starts at 0. ==> - 1
    int currentRound{m_game->getGameRoundManager()->getRound()};
    int currentFirstPlayer{m_game->getGameRoundManager()->getFirstPlayerIndex()};

    Player* currentPlayer{m_players.at(((currentRound + currentFirstPlayer) - 1) % TOTAL_ROUNDS)};
    return currentPlayer;
}

Player* Players::getNextPlayer() const {
    // Round starts at 1, array starts at 0. ==> - 1
    int currentRound{m_game->getGameRoundManager()->getRound()};
    int currentFirstPlayer{m_game->getGameRoundManager()->getFirstPlayerIndex()};

    Player* nextPlayer{m_players.at(((currentRound + currentFirstPlayer)) % TOTAL_ROUNDS)};
    qDebug() << nextPlayer->getName() << " is the next player";
    return nextPlayer;
}

int Players::getSize() const {
    return m_players.size();
}

bool Players::lastPlayerWithWorkers(Team team) const {
    for(int i{0}; i < m_players.size(); ++i) {
        if(!m_players.at(i)->getPlayerBoard()->getWorkers()->areAllWorkersUsed() && m_players.at(i)->getTeam() != team) {
            return false;
        }
    }
    return true;
}


// Utils
bool Players::usedAllWorkers() const {
    for(int i{0}; i < m_players.size(); ++i) {
        if(!getPlayer(i)->getPlayerBoard()->getWorkers()->areAllWorkersUsed())
            return false;
    }
    return true;
}

void Players::deActivateAll() {
    foreach(Player* player, m_players) {
        player->getPlayerBoard()->unsetActive();
    }
}

void Players::unsetWorkersPlacement() {
    foreach(Player* player, m_players) {
        player->getPlayerBoard()->getWorkers()->unsetPlacedWorkerThisRound();
    }
}


void Players::updateBuildingCardInventory() {
    QVector<BuildingCard*> cards{getCurrentPlayer()->getPlayerBoard()->getCollectedBuildingCards()};
    QVector<QString> paths{};

    foreach(BuildingCard* card, cards) {
        paths.append(card->getImagePath());
    }

    emit s_updateBuildingInventory(paths);
}

void Players::updateCivilisationCardInventory() {
    QVector<CivilisationCard*> cards{getCurrentPlayer()->getPlayerBoard()->getCollectedCivilisationCards()};
    QVector<QString> paths{};

    foreach(CivilisationCard* card, cards) {
        paths.append(card->getImagePath());
    }

    emit s_updateCivilisationInventory(paths);
}
