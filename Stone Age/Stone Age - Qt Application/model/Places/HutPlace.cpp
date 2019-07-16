#include "HutPlace.h"
#include "../../config.h"

#include "../PlayerBoard.h"
#include "../Player.h"
#include "../Game.h"
#include "../PlayerBoardItems/Worker.h"
#include "../PlayerBoardItems/Workers.h"


// Constructor
HutPlace::HutPlace(QString name, int maximumWorkerAmount, Game* game) : Place (name, maximumWorkerAmount, game) {}


// Utils
void HutPlace::calculateMaterials(Player *player, int currentWorkers) {
    PlayerBoard* playerBoard{player->getPlayerBoard()};

    playerBoard->getWorkers()->increaseWorkersCapacity(currentWorkers/2);

    playerBoard->updatePlayerBoard();
}
