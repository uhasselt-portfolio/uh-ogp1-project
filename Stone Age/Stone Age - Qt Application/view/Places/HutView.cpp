#include <QDebug>

#include "HutView.h"
#include "../../model/Game.h"
#include "../../model/Place.h"

#include "../../model/GameBoard.h"
#include "../../model/Player.h"
#include "../../model/Places.h"
#include "../../model/Places/HutPlace.h"
#include "../../model/PlayerBoard.h"

// Constructor
HutView::HutView(int x, int y, int w, int h, QGraphicsItem *parent, Game *game, Place *place) :
    PlaceView{x, y, w, h, parent, game, place} {}


// Events
void HutView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    (void)event;
    m_game->getGameBoard()->getPlaces()->getHut()->handleClickEvent(2);
}
