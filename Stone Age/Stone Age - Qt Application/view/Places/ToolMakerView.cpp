#include <QDebug>

#include "ToolMakerView.h"
#include "../../model/Game.h"
#include "../../model/Place.h"

#include "../../model/GameBoard.h"
#include "../../model/Player.h"
#include "../../model/Places.h"
#include "../../model/Places/ToolMakerPlace.h"
#include "../../model/PlayerBoard.h"

// Constructor
ToolMakerView::ToolMakerView(int x, int y, int w, int h, QGraphicsItem *parent, Game *game, Place *place) :
    PlaceView{x, y, w, h, parent, game, place} {}

// Events
void ToolMakerView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    (void)event;
    m_game->getGameBoard()->getPlaces()->getToolMaker()->handleClickEvent();
}
