#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVector>

class Players;
class GameBoard;
class Place;
class GameRoundManager;
class Tool;
class CardStack;

class Game : public QObject {
    Q_OBJECT

    public:
        // Constructor
        Game();

        // Getters
        Players* getPlayers() const;
        GameBoard* getGameBoard() const;
        GameRoundManager* getGameRoundManager() const;
        bool isGameFinished() const;

        // Utils
        void start();
        void stop();
        void load();
        void save();
        void updateAllPlayerBoards();
        void announce(QString text);
        void announceResources(QVector<int> dice, QString calc, QString resType, QVector<Tool*> tools);

    signals:
        void s_announce(QString text);
        void s_announceResources(QVector<int> dice, QString calc, QString resType, QVector<Tool*> tools);

    public slots:
        void r_save();
        void r_load();

    private:
        // Variables
        GameRoundManager* m_gameRoundManager;
        Players* m_players;
        GameBoard* m_gameBoard;
};

#endif // GAME_H
