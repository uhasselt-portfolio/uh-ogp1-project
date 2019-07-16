#ifndef PLAYERBOARDVIEW_H
#define PLAYERBOARDVIEW_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QString>

#include "../../model/Team.h"
#include "../../model/PlayerBoardItems/Tools.h"

class Game;
class PlayerTextView;
class ToolView;
class Tools;

class PlayerBoardView : public QObject, public QGraphicsRectItem {
    Q_OBJECT

    public:
        // Constructor
        PlayerBoardView(int x, int y, int w, int h, QGraphicsScene *scene = nullptr, Game* game = nullptr, Team team = Team::RED);

        // Initializers
        void initSecondRow();
        void initThirdRow();
        void initFourthRow();

        // Setters
        void setName(QString name);
        void setScore(QString score);

        // Utils
        void setActive(bool active);
        void updateTools(Tools* tools);


    public slots:
        void r_setActiveState(bool active);
        void r_renderPlayerBoard(QString worker="", QString food="", QString score="", QString wood="", QString stone="", QString brick="", QString gold="", Tools* tools=nullptr);

    private:
        Game *m_game;
        // Player info
        QString m_playerColor;

        // Player text
        PlayerTextView *m_name;
        PlayerTextView *m_score;

        PlayerTextView *m_workers;
        PlayerTextView *m_food;
        PlayerTextView *m_farm;

        PlayerTextView *m_wood;
        PlayerTextView *m_brick;
        PlayerTextView *m_stone;
        PlayerTextView *m_gold;

        QVector<ToolView*> m_tools;

        Team m_team;
};

#endif // PLAYERBOARD_H
