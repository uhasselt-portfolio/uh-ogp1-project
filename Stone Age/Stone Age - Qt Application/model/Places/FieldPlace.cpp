#include "FieldPlace.h"
#include "../../config.h"

#include "../PlayerBoardItems/Worker.h"
#include "../Player.h"
#include "../Game.h"
#include "../Dice.h"
#include "../PlayerBoard.h"
#include "../PlayerBoardItems/Resource.h"
#include "../PlayerBoardItems/FoodTracker.h"

// Constructor
FieldPlace::FieldPlace(QString name, int maximumWorkerAmount, Game* game) : Place (name, maximumWorkerAmount, game) {}


// Utils
void FieldPlace::calculateMaterials(Player *player, int currentWorkers) {
    (void) currentWorkers;
    PlayerBoard* playerBoard{player->getPlayerBoard()};
    playerBoard->getFoodTracker()->increaseFoodLevel();
    playerBoard->updatePlayerBoard();

    emit s_updateFarmerLevel(playerBoard->getFoodTracker()->getFoodLevel() ,player->getTeam());
}
