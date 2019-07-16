#include <QRect>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QString>

#include "PlayerBoardView.h"
#include "PlayerTextView.h"
#include "../../config.h"
#include "../../model/Game.h"
#include "../../model/Seeder.h"

#include "../../model/Player.h"
#include "../../model/PlayerBoard.h"
#include "../../model/PlayerBoardItems/ScoreTracker.h"
#include "../../model/PlayerBoardItems/Worker.h"
#include "../../model/PlayerBoardItems/Workers.h"
#include "../../model/PlayerBoardItems/FoodTracker.h"
#include "../../model/PlayerBoardItems/Food.h"
#include "../../model/PlayerBoardItems/Resource.h"
#include "../../model/PlayerBoardItems/Tools.h"
#include "../../model/PlayerBoardItems/Tool.h"

#include "../Items/WorkerView.h"
#include "../Items/ResourceView.h"
#include "../Items/ToolView.h"

// Constructor
PlayerBoardView::PlayerBoardView(int x, int y, int w, int h, QGraphicsScene *scene, Game* game, Team team) : QGraphicsRectItem{QRect{0, 0, w*SCALE, h*SCALE}}, m_game{game}, m_team{team} {
    // Set color and pos
    setBrush(QBrush{QColor{235, 213, 189}});
    setPen(Qt::NoPen);
    setPos(x*SCALE, y*SCALE);

    initSecondRow();
    initThirdRow();
//    initFourthRow();

    if (scene != nullptr)
        scene->addItem(this);
}


// Initializers
void PlayerBoardView::initSecondRow() {
    new WorkerView{m_team, 2, 50, 16, this};
    m_workers = new PlayerTextView{22, 48, 0, 16, "", this};

    new ResourceView{90, 50, 20, "food", this};
    m_food = new PlayerTextView{112, 48, 0, 16, "", this};
}
void PlayerBoardView::initThirdRow() {
    // Set default font
    QFont defaultFont{};
    defaultFont.setPixelSize(16*SCALE);

    // Wood
    new ResourceView{2, 80, 20, "wood", this};
    m_wood = new PlayerTextView{27, 78, 0, 16, "", this};

    // Brick
    new ResourceView{60, 80, 20, "brick", this};
    m_brick = new PlayerTextView{87, 78, 0, 16, "", this};

    // Stone
    new ResourceView{118, 80, 20, "stone", this};
    m_stone = new PlayerTextView{145, 78, 0, 16, "", this};

    // Gold
    new ResourceView{176, 80, 20, "gold", this};
    m_gold = new PlayerTextView{203, 78, 0, 16, "", this};
}
void PlayerBoardView::initFourthRow() {
    for(int i{0}; i < 4; ++i) {
        new ToolView{5 + 30*i, 110, 25, 2, this};
    }
}


// Setters
void PlayerBoardView::setName(QString name) {
    m_name = new PlayerTextView{0, 0, 2, 16, name, this};
}
void PlayerBoardView::setScore(QString score) {
    m_score = new PlayerTextView{0, 20, 2, 16, score, this};
}
void PlayerBoardView::setActive(bool active) {
    active ? setBrush(QBrush{QColor{215, 203, 169}}) : setBrush(QBrush{QColor{235, 213, 189}});
}
void PlayerBoardView::updateTools(Tools* tools) {
    foreach(ToolView* tool, m_tools) {
        delete tool;
    }

    int offset{5};
    QVector<ToolView*> newTools{};
    QVector<Tool*> allTools{tools->getTools()};

    foreach(Tool* tool, allTools) {
        newTools.append(new ToolView{offset, 110, 25, tool->getLevel(), this});
        offset += 5 + 25;
    }

    m_tools = newTools;
}


// Slots
void PlayerBoardView::r_setActiveState(bool active) {
    setActive(active);
}


void PlayerBoardView::r_renderPlayerBoard(QString worker, QString food, QString score, QString wood, QString stone, QString brick, QString gold, Tools* tools) {
    m_workers->setPlainText(worker);
    m_food->setPlainText(food);
    m_score->setPlainText(score);
    m_wood->setPlainText(wood);
    m_stone->setPlainText(stone);
    m_brick->setPlainText(brick);
    m_gold->setPlainText(gold);

    updateTools(tools);
}
