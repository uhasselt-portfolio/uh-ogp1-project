#ifndef GAMEROUNDMANAGER_H
#define GAMEROUNDMANAGER_H

#include "QObject"
#include "QVector"

class Players;
class Game;

class GameRoundManager : public QObject {
    Q_OBJECT
    public:
        // Constructor
        GameRoundManager(Players* players, int round, int phase, int firstPlayerIndex, Game* game = nullptr);

        // Getters
        int getRound() const;
        int getPhase() const;
        int getFirstPlayerIndex() const;

        // Setters
        void setRound(int round);
        void setPhase(int phase);
        void setFirstPlayerIndex(int index);

        // Utils
        void nextGameRound();

    signals:
        void s_endGame();

    private:
        Players* m_players;
        int m_round;
        int m_phase;
        int m_firstPlayerIndex;
        Game* m_game;
        bool m_gameFinished;

        void nextRound();
        void nextPhase();
        void updateFirstPlayer();
        bool didPlayerSetWorers() const;
        bool isFinalRoundActivated() const;
};

#endif // GAMEROUNDMANAGER_H
