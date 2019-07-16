#include <QDebug>

#include "ForestView.h"
#include "../../model/Game.h"
#include "../../model/Place.h"

#include "../../model/GameBoard.h"
#include "../../model/Player.h"
#include "../../model/Places.h"
#include "../../model/Places/ForestPlace.h"
#include "../../model/PlayerBoard.h"

ForestView::ForestView(int x, int y, int w, int h, QGraphicsItem *parent, Game* game, Place* place) :
    PlaceView{x, y, w, h, parent, game, place}{
}

void ForestView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    (void)event;
    m_game->getGameBoard()->getPlaces()->getForest()->handleClickEvent();
}
