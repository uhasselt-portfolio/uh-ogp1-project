#ifndef GAMEMENUVIEW_H
#define GAMEMENUVIEW_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

class GameButtonView;

class GameMenuView : public QGraphicsRectItem {
    public:
        // Constructor
        GameMenuView(int x, int y, int w, int h, QGraphicsScene *scene = nullptr);

        // Getters
        GameButtonView* getStartBtn();
        GameButtonView* getQuitBtn();
        GameButtonView* getLoadBtn();
        GameButtonView* getSaveBtn();

        // Utils
        void gameStarted();

    private:
        GameButtonView* m_startBtn;
        GameButtonView* m_saveBtn;
        GameButtonView* m_loadBtn;
        GameButtonView* m_quitBtn;
};

#endif // GAMEMENUVIEW_H
