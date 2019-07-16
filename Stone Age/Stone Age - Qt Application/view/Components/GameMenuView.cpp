#include <QPen>
#include <QBrush>
#include <QColor>
#include <QPixmap>

#include "../../config.h"
#include "GameMenuView.h"
#include "GameButtonView.h"


// Constructor
GameMenuView::GameMenuView(int x, int y, int w, int h, QGraphicsScene *scene) : QGraphicsRectItem{QRect{0, 0, w*SCALE, h*SCALE}} {

    QGraphicsPixmapItem* bg{new QGraphicsPixmapItem{QPixmap{":/images/images/menubg.jpg"}.scaled(1400*SCALE, 828*SCALE)}};
    bg->setPos(0, 0);
    bg->setParentItem(this);
    bg->setOpacity(0.55);

    setPos(x*SCALE, y*SCALE);

    setPen(Qt::NoPen);
    setBrush(QBrush{QColor{122, 117, 104}});

    QGraphicsTextItem* stoneAge{new QGraphicsTextItem{"Stone Age", this}};
    QFont title{};
    title.setPixelSize(70*SCALE);
    stoneAge->setFont(title);
    int screenWidth{int(this->boundingRect().width())};
    int textWidth{int(stoneAge->boundingRect().width())};

    stoneAge->setPos(screenWidth/2 - textWidth/2, 40);


    m_startBtn = new GameButtonView{125, 30, "Start", this};
    m_saveBtn = new GameButtonView{175, 30, "Save", this};
    m_saveBtn->hide();

    m_loadBtn = new GameButtonView{175, 30, "Load", this};
    m_quitBtn = new GameButtonView{225, 30, "Quit", this};


    // Adding item to scene
    if (scene != nullptr)
        scene->addItem(this);
}


// Getters
GameButtonView* GameMenuView::getStartBtn() {
    return m_startBtn;
}
GameButtonView *GameMenuView::getQuitBtn() {
    return m_quitBtn;
}
GameButtonView *GameMenuView::getLoadBtn() {
    return m_loadBtn;
}
GameButtonView *GameMenuView::getSaveBtn() {
    return m_saveBtn;
}

void GameMenuView::gameStarted() {
    m_saveBtn->show();
    m_loadBtn->hide();
}
