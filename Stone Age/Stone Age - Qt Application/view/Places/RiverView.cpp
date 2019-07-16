#include <QDebug>

#include "RiverView.h"
#include "../../model/Game.h"
#include "../../model/Place.h"

#include "../../model/GameBoard.h"
#include "../../model/Player.h"
#include "../../model/Places.h"
#include "../../model/Places/RiverPlace.h"
#include "../../model/PlayerBoard.h"

// Constructor
RiverView::RiverView(int x, int y, int w, int h, QGraphicsItem *parent, Game *game, Place *place) :
    PlaceView{x, y, w, h, parent, game, place} {}


// Events
void RiverView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    (void)event;
    m_game->getGameBoard()->getPlaces()->getRiver()->handleClickEvent();
}
