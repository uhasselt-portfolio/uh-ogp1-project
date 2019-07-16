#include <QPen>
#include <QBrush>
#include <QColor>
#include <QFont>

#include "model/Places/BuildingCardPlace.h"
#include "model/Places/CivilisationCardPlace.h"

#include "AnnounceView.h"
#include "../../config.h"

#include "../Components/GameButtonView.h"
#include "../Components/GameTextView.h"
#include "../Items/DiceView.h"
#include "../Items/ToolView.h"
#include "../Items/ResourceView.h"

#include "../../model/PlayerBoardItems/Tool.h"

#include "../../model/Game.h"
#include "../../model/Player.h"
#include "../../model/Players.h"
#include "../../model/Place.h"
#include "../../model/Places.h"
#include "../../model/GameBoard.h"
#include "../../model/Cards/BuildingCard.h"
#include "../../model/Cards/CivilisationCard.h"


// Constructor
AnnounceView::AnnounceView(int x, int y, int w, int h, QGraphicsScene *scene, Game* game) : QGraphicsRectItem{QRect{0, 0, w*SCALE, h*SCALE}}, m_announceText{new QGraphicsTextItem{this}}, m_game{game} {
    setPos(x*SCALE, y*SCALE);
    setPen(Qt::NoPen);
    setBrush(QBrush{QColor{226, 218, 208}});

    m_smallFont.setPixelSize(SCALE*16);
    m_bigFont.setPixelSize(SCALE*27);

    if (scene != nullptr)
        scene->addItem(this);

//    new GameButtonView{12, 20, "TEST", this};

    m_claimBtn = new GameButtonView{12, 70, 20, "claim", this};
    m_payBtn = new GameButtonView{12, 70, 20, "pay", this};
    m_claimBtn->hide();
    m_payBtn->hide();

    m_nextBtn = new GameButtonView{12, 10, 20, "next", this};
}


// Getters
GameButtonView *AnnounceView::getNextBtn() const {
    return m_nextBtn;
}
GameButtonView *AnnounceView::getPayBtn() const {
    return m_payBtn;
}


// Utils
void AnnounceView::announceBig(QString text) {
    clean();
    m_announceText->show();
    m_announceText->setPlainText(text);
    m_announceText->setPos(10*SCALE, 10*SCALE);
    m_announceText->setFont(m_bigFont);
}
void AnnounceView::announceSmall(QString text) {
    clean();
    m_announceText->show();
    m_announceText->setPlainText(text);
    m_announceText->setPos(10*SCALE, 10*SCALE);
    m_announceText->setFont(m_smallFont);
}
void AnnounceView::announceRecources(QVector<int> dice, QString calc, QString resType, QVector<Tool*> tools) {
    clean();
    m_claimBtn->show();

    int xOffset{5};
    foreach(int i, dice) {
        new DiceView{xOffset, 5, 25, i, this};
        xOffset += 25 + 5;
    }
    xOffset += 5;
    QGraphicsTextItem* calculateText{new QGraphicsTextItem{calc, this}};
    calculateText->setPos(xOffset*SCALE, 5*SCALE);
    QFont calcFont{};
    calcFont.setPixelSize(17*SCALE);
    calculateText->setFont(calcFont);
    int width{int(calculateText->boundingRect().width()) / SCALE};
    xOffset += width+2;
    new ResourceView{xOffset, 10, 20, resType, this};


    // Print tools (active, unactive)
    xOffset = 5;
    foreach(Tool* tool, tools) {

        ToolView* currentTool{new ToolView{xOffset, 35, 25, tool->getLevel(), this, true, m_game}};
        xOffset += 25 + 5;

        if (tool->isUsedThisRound()) {
            currentTool->setInactive();
        }
    }


    // Claim button
    connect(m_claimBtn, &GameButtonView::s_buttonClicked, this, &AnnounceView::r_claimRescources);
}
void AnnounceView::announcePayResources(BuildingCardPlace* place, QVector<int> resources,  bool changeable) {
    clean();
    m_payBtn->show();

    int xOffset{10};
    QVector<QString> resTypes{"wood", "brick", "stone", "gold"};

    for(int i{0}; i < AMOUNT_RESOURCE_TYPES; ++i) {
        ResourceView* currentRes{new ResourceView{xOffset, 10, 25, resTypes[i], this, changeable}};
        currentRes->setBuildingCardPlace(place);

        xOffset += 30 + 5;
    }

    xOffset = 14;
    for(int i{0}; i < AMOUNT_RESOURCE_TYPES; ++i) {
        new GameTextView{xOffset, 30, 25, QString::number(resources[i]), this};
        xOffset += 30 + 5;
    }
}

void AnnounceView::clean() {
    foreach(QGraphicsItem* item, childItems()) {
        if (!(item == m_announceText || item == m_nextBtn || item == m_claimBtn || item == m_payBtn))
            delete item;
        else
            item->hide();
    }

    m_nextBtn->show();
}

// Slots
void AnnounceView::r_announceSmall(QString text) {
    announceSmall(text);
}
void AnnounceView::r_announceResources(QVector<int> dice, QString calc, QString resType, QVector<Tool*> tools) {
    announceRecources(dice, calc, resType, tools);
}
void AnnounceView::r_announcePayResources(BuildingCardPlace* bPlace, CivilisationCardPlace* cPlace, QVector<int> resources, bool changeable) {
    clean();
    m_payBtn->show();

    int xOffset{10};
    QVector<QString> resTypes{"wood", "brick", "stone", "gold"};

    for(int i{0}; i < AMOUNT_RESOURCE_TYPES; ++i) {
        ResourceView* currentRes{new ResourceView{xOffset, 10, 25, resTypes[i], this, changeable}};
        (bPlace == nullptr) ? currentRes->setCivilCardPlace(cPlace) : currentRes->setBuildingCardPlace(bPlace);

        xOffset += 30 + 5;
    }

    xOffset = 14;
    for(int i{0}; i < AMOUNT_RESOURCE_TYPES; ++i) {
        new GameTextView{xOffset, 30, 25, QString::number(resources[i]), this};
        xOffset += 30 + 5;
    }
}

void AnnounceView::r_payResources() {
    BuildingCardPlace* activeBuildingPlace{m_game->getGameBoard()->getActiveBuildingCardPlace()};
    CivilisationCardPlace* activeCivilPlace{m_game->getGameBoard()->getActiveCivilCardPlace()};

    (activeBuildingPlace == nullptr) ? activeCivilPlace->pay() : activeBuildingPlace->pay();
}

void AnnounceView::r_claimRescources() {
    Place* activePlace{m_game->getGameBoard()->getPlaces()->getLastClickedPlace()};
    activePlace->claimResources();
}
