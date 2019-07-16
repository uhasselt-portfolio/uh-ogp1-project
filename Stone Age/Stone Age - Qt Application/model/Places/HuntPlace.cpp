#include "HuntPlace.h"
#include "../../config.h"

#include "../PlayerBoardItems/Worker.h"
#include "../Player.h"
#include "../Game.h"
#include "../PlayerBoard.h"
#include "../PlayerBoardItems/Food.h"
#include "../PlayerBoardItems/Resource.h"
#include "ResourcePlace.h"
#include "../Dice.h"


// Constructor
HuntPlace::HuntPlace(QString name, int maximumWorkerAmount, Game* game) :
    Place (name, maximumWorkerAmount, game) , ResourcePlace{"food", -1, 2} {}


// Utils
void HuntPlace::calculateMaterials(Player *player, int currentWorkers) {
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

void HuntPlace::updateCalcView(Player* player, int toolLevel) {
    updateCalcViewHelper(toolLevel, m_game, player);
}

void HuntPlace::claimResources() {
    if (!m_resourcesClaimed) {
        PlayerBoard* playerBoard{m_currentPlayer->getPlayerBoard()};
        playerBoard->getFoodStock()->increaseFoodSupply((m_diceSum+m_toolLevel) / m_resReturnValue);
        playerBoard->updatePlayerBoard();

        m_resourcesClaimed = true;
        m_game->announce("Je hebt je resources gekregen.");
    }
}

