#include <QFont>
#include <QPen>
#include <QDebug>

#include "GameButtonView.h"
#include "../../config.h"


// Constructors
GameButtonView::GameButtonView(int top, int size, QString text, QGraphicsItem *parent) : QGraphicsRectItem{}, m_top{top*SCALE}, m_size{size*SCALE} {
    // Button text
    QFont buttonFont{};
    buttonFont.setFamily("Bavaria");
    buttonFont.setPixelSize(size*SCALE);

    m_buttonText = new QGraphicsTextItem{text, this};
    m_buttonText->setFont(buttonFont);
    int textWidth{int(m_buttonText->boundingRect().width())};

    // Set button bordeer
    setFlag(ItemIsSelectable);
    setPen(Qt::NoPen);
    setRect(0, 0, textWidth + PADDING*2, size*SCALE + PADDING*4);

    // Set text as parent inside
    m_buttonText->setParentItem(this);
    m_buttonText->setPos(PADDING, PADDING);

    // Center button to parent
    int screenWidth{int(parent->boundingRect().width())};
    setPos(screenWidth/2 - (textWidth + PADDING*2)/2, top*SCALE);
    setParentItem(parent);
}
GameButtonView::GameButtonView(int top, int right, int size, QString text, QGraphicsItem *parent) : m_top{top*SCALE}, m_size{size*SCALE} {
    // Button text
    QFont buttonFont{};
    buttonFont.setFamily("times");
    buttonFont.setPixelSize(size*SCALE);
    m_buttonText = new QGraphicsTextItem{text, this};
    m_buttonText->setFont(buttonFont);
    int textWidth{int(m_buttonText->boundingRect().width())};

    // Set button border
    setFlag(ItemIsSelectable);  
    setPen(QPen{QBrush{QColor{0, 0, 0}}, 1});
    setRect(0, 0, textWidth + PADDING*2, size*SCALE + PADDING*4);

    // Set text as parent inside
    m_buttonText->setParentItem(this);
    m_buttonText->setPos(PADDING, PADDING);

    // left btn
    int screenWidth{int(parent->boundingRect().width())};
    setPos(screenWidth - (textWidth + PADDING*2) - right*SCALE, top*SCALE);
    setParentItem(parent);
}

void GameButtonView::setBtnText(QString text, QGraphicsItem* parent) {
    m_buttonText->setPlainText(text);
    int textWidth{int(m_buttonText->boundingRect().width())};
    setRect(0, 0, textWidth + PADDING*2, m_size + PADDING*4);
    int screenWidth{int(parent->boundingRect().width())};
    setPos(screenWidth/2 - (textWidth + PADDING*2)/2, m_top);
}

void GameButtonView::moveDown(int amount, QGraphicsItem* parent) {
    int textWidth{int(m_buttonText->boundingRect().width())};
    int screenWidth{int(parent->boundingRect().width())};
    setPos(screenWidth/2 - (textWidth + PADDING*2)/2, m_top+amount*SCALE);
}


// Events
void GameButtonView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    (void)event;
    emit s_buttonClicked("Start");
}





