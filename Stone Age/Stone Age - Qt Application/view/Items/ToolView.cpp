#include "ToolView.h"
#include "../../config.h"
#include "../../model/Game.h"
#include "../../model/Player.h"
#include "../../model/Players.h"
#include "../../model/PlayerBoard.h"
#include "../../model/PlayerBoardItems/Tools.h"


// Constructor
ToolView::ToolView(int x, int y, int size, int level, QGraphicsItem *parent, bool selectable, Game* game) :QGraphicsPixmapItem{parent}, m_game{game}, m_level{level} {
    setPos(x*SCALE, y*SCALE);
    setPixmap(QPixmap{":/images/images/tools/tool"+ QString::number(level) +".jpg"}.scaledToWidth(size*SCALE));
    selectable ? setFlag(ItemIsSelectable) : (void)selectable;
}


// Setters (visuals)
void ToolView::setInactive() {
    setOpacity(0.6);
    setFlag(ItemIsSelectable, false);
}


// Events
void ToolView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    (void)event;

    setInactive();

    // Send signal
    m_game->getPlayers()->getCurrentPlayer()->getPlayerBoard()->getTools()->useTool(this->m_level);
}
