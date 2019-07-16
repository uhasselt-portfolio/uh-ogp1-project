#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

#include "Team.h"

class PlayerBoard;
class Game;

class Player {
    public:
        // Constructor
        Player(QString name, Team team, Game* game=nullptr);

        // Getters
        QString getName() const;
        PlayerBoard* getPlayerBoard() const;
        Team getTeam() const;

        // Setters
        void setName(QString name);
        void setTeam(Team team);
        void setPlayerBoard(PlayerBoard*); // TODO: Waarschijnlijk niet nodig

    private:
        QString m_name;
        PlayerBoard* m_playerBoard;
        Team m_team;
};

#endif // PLAYER_H
