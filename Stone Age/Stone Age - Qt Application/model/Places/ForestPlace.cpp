#include <QDebug>

#include "ForestPlace.h"
#include "../../config.h"

#include "../PlayerBoardItems/Worker.h"
#include "../Player.h"
#include "../Game.h"
#include "../Dice.h"
#include "../PlayerBoard.h"
#include "../PlayerBoardItems/Resource.h"
#include "../PlayerBoardItems/Tools.h"

// Constructor
ForestPlace::ForestPlace(QString name, int maximumWorkerAmount, Game* game) :
    Place{name, maximumWorkerAmount, game}, ResourcePlace{"wood", WOOD_RESOURCE, FOREST_RESOURCE_RETURN} {}


// Utils
void ForestPlace::calculateMaterials(Player *player, int currentWorkers) {
    Dice dice{currentWorkers};
    dice.roll();

    m_resourcesClaimed = false;
    m_dice = dice.getDice();
    m_diceSum = dice.getDiceSum();
    m_currentPlayer = player;
    m_total = m_diceSum / m_resReturnValue;
    m_toolLevel = 0;

    updateAnnounceResources(m_diceSum, m_game, player);
}

void ForestPlace::updateCalcView(Player* player, int toolLevel) {
    updateCalcViewHelper(toolLevel, m_game, player);
}

void ForestPlace::claimResources() {
    claimResourceHelper(m_game);
}
