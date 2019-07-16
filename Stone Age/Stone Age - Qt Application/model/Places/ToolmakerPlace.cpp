#include "ToolMakerPlace.h"
#include "../../config.h"

#include "../PlayerBoardItems/Worker.h"
#include "../Player.h"
#include "../Game.h"
#include "../Dice.h"
#include "../PlayerBoard.h"
#include "../PlayerBoardItems/Tools.h"
#include "../PlayerBoardItems/Tool.h"

// Constructor
ToolMakerPlace::ToolMakerPlace(QString name, int maximumWorkerAmount, Game* game) : Place (name, maximumWorkerAmount, game) {}


// Utils
void ToolMakerPlace::calculateMaterials(Player *player, int currentWorkers) {
    (void)currentWorkers;

    PlayerBoard* playerBoard{player->getPlayerBoard()};
    playerBoard->getTools()->upgradeNextTool();
    playerBoard->updatePlayerBoard();
}
