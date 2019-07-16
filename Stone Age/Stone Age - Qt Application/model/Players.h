#ifndef PLAYERS_H
#define PLAYERS_H

#include <QVector>
#include <QObject>

#include "Team.h"

class Player;
class Game;

class Players : public QObject {
    Q_OBJECT
    public:

        // Constructor
        Players(QVector<Player*> players, Game* game);

        // Getters
        Player* getPlayer(int playerIndex = 0) const;
        Player* getPlayer(Team team) const;
        Player* getCurrentPlayer() const;
        Player* getNextPlayer() const;
        int getSize() const;
        bool lastPlayerWithWorkers(Team team) const;

        // Utils
        bool usedAllWorkers() const;
        void deActivateAll();
        void unsetWorkersPlacement();

        void updateBuildingCardInventory();
        void updateCivilisationCardInventory();

    signals:
        void s_updateBuildingInventory(QVector<QString> paths);
        void s_updateCivilisationInventory(QVector<QString> paths);

    private:
        QVector<Player*> m_players;
        Game* m_game;
};

#endif // PLAYERS_H
