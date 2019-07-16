#include <QDebug>

#include "CivilisationCardView.h"
#include "../../model/Game.h"
#include "../../model/Place.h"

#include "../Cards/CardView.h"

#include "../../model/GameBoard.h"
#include "../../model/Player.h"
#include "../../model/Players.h"
#include "../../model/Places.h"
#include "../../model/PlacedCards.h"
#include "../../model/PlayerBoard.h"
#include "../../model/Places/CivilisationCardPlace.h"
#include "../../model/Cards/CivilisationCard.h"
#include "../../model/GameRoundManager.h"


// Constructor
CivilisationCardView::CivilisationCardView(int x, int y, int w, int h, CivilisationCardPlace *civilisationCardPlace, QGraphicsItem *parent, Game *game, Place *place)
    : PlaceView{x, y, w, h, parent, game, place}, m_civilisationCardPlace{civilisationCardPlace} {

}

// Getters
CardView *CivilisationCardView::getCard() const {
    // TODO: change later
    return reinterpret_cast<CardView*>(childItems()[0]);
}


// Events
void CivilisationCardView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    (void)event;
    m_civilisationCardPlace->collect();
}

// Slots
void CivilisationCardView::r_removeCivilisationCardView() {
    delete m_cardView;
}

void CivilisationCardView::r_addCivilisationCardView(QString imageName) {
    this->addCard(new CardView{":/images/images/cards/civil/" + imageName + ".jpg", 0, 0, 85});
}




