#include <QDebug>

#include "BuildingCardView.h"
#include "../../model/Game.h"
#include "../../model/Place.h"
#include "../Cards/CardView.h"

#include "../../model/GameBoard.h"
#include "../../model/Player.h"
#include "../../model/Players.h"
#include "../../model/Places.h"
#include "../../model/PlacedCards.h"
#include "../../model/PlayerBoard.h"
#include "../../model/Places/BuildingCardPlace.h"
#include "../../model/Cards/BuildingCard.h"
#include "../../model/GameRoundManager.h"

#include "../Cards/CardView.h"

// Constructor
BuildingCardView::BuildingCardView(int x, int y, int w, int h, BuildingCardPlace* buildingCardPlace, QGraphicsItem *parent, Game *game, Place *place) :
    PlaceView{x, y, w, h, parent, game, place}, m_buildingCardPlace{buildingCardPlace} {}

CardView *BuildingCardView::getCard() const {
    return m_cardView;
}


// Events
void BuildingCardView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    (void)event;
    m_buildingCardPlace->collect();
}

// Slots
void BuildingCardView::r_removeBuildingCardView() {
    delete m_cardView;
}

void BuildingCardView::r_addBuildingCardView(QString imageName) {
    this->addCard(new CardView{":/images/images/cards/building/" + imageName + ".jpg", 0, 0, 68});
}
