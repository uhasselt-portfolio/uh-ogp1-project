#include "Player.h"
#include "Seeder.h"
#include "Team.h"
#include "PlayerBoard.h"

// Constructor
Player::Player(QString name, Team team, Game* game) : m_name{name}, m_team{team} {
    Seeder seeder{};
    m_playerBoard = seeder.loadPlayerBoard(team, game);
}

// Getters
QString Player::getName() const {
    return m_name;
}

PlayerBoard* Player::getPlayerBoard() const {
    return m_playerBoard;
}

Team Player::getTeam() const {
    return m_team;
}

// Setters
void Player::setName(QString name) {
    m_name = name;
}

void Player::setTeam(Team team) {
    m_team = team;
}
