#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsScene>
#include <QObject>
#include <QVector>

class Game;
class GameMenuView;
class BoardView;
class PlayerBoardView;
class PlayerBoard;
class AnnounceView;
class CardInventoryView;
class EndGameView;


class GameView : public QGraphicsScene {
    Q_OBJECT

    public:
        // Constructor
        GameView(QObject *parent = nullptr, Game* game = nullptr);

        // Init
        void initAnnounceBar();
        void initGameBoard();
        void initPlayerBoards();
        void initCivilisationCards();
        void initBuildingCards();
        void initGameInfo();
        void initEndGameScreen();

        void initGameMenu();

        // Getters
        GameMenuView* getGameMenu() const;
        BoardView* getGameBoard() const;
        PlayerBoardView* getPlayerBoard(int index) const;

        // Utils
        void hideGameMenu();
        void connectAll();


    public slots:
        void r_renderGameBoard();
        void r_updateRound();
        void r_toggleMenu();
        void r_endGame();

    private:
        Game* m_game;
        BoardView* m_gameBoard;
        AnnounceView* m_announceView;
        QVector<PlayerBoardView*> m_playerBoards;
        GameMenuView* m_gameMenu;
        EndGameView* m_endGame;

        CardInventoryView* m_buildingView;
        CardInventoryView* m_civilView;
        QGraphicsRectItem* m_gameInfoView;
};

#endif // GAMEVIEW_H
