#include "CardInventoryView.h"
#include "../Cards/CardView.h"
#include "../../config.h"


// Constructors
CardInventoryView::CardInventoryView(int x, int y, int w, int h, QGraphicsScene* scene) {
    setRect(0, 0, w*SCALE, h*SCALE);
    setPos(x*SCALE, y*SCALE);

    setPen(Qt::NoPen);
    setBrush(QBrush{QColor{165, 159, 152}});

    if (scene != nullptr)
        scene->addItem(this);
}

// Visuals
void CardInventoryView::displayCards(QVector<QString> paths, QString pathPrefix) {
    int padding{20*SCALE};

    m_rows = 3;
    m_cols = 8;

    m_cardX = (int(boundingRect().width()) / m_cols) - padding;
    m_cardY = (int(boundingRect().height()) / m_rows) - padding;

    int xOffset{padding/2};
    int yOffset{padding/2};

    for(int i{0}, l{paths.size()}; i < l; ++i) {
        QString path{paths[i]};
        CardView* newCard{new CardView{pathPrefix + path + ".jpg", xOffset, yOffset, int(m_cardX/SCALE), this}};
        m_cards.append(newCard);

        xOffset += m_cardX + padding/2;
        if ((i+1) % (m_cols+1) == 0) {
            yOffset += m_cardY + padding/2;
            xOffset = padding/2;
        }
    }

}

void CardInventoryView::removeCards() {
    foreach(CardView* card, m_cards) {
        delete card;
    }

    m_cards = {};
}

void CardInventoryView::r_updateBuildingInventory(QVector<QString> paths) {
    removeCards();
    displayCards(paths, ":/images/images/cards/building/");
}

void CardInventoryView::r_updateCivilisationInventory(QVector<QString> paths) {
    removeCards();
    displayCards(paths, ":/images/images/cards/civil/");
}
