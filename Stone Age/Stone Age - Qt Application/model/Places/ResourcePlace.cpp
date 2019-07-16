#include "ResourcePlace.h"

#include "../../config.h"
#include "../Player.h"
#include "../PlayerBoard.h"
#include "../Game.h"
#include "../PlayerBoardItems/Tool.h"
#include "../PlayerBoardItems/Tools.h"
#include "../PlayerBoardItems/Resource.h"

// Constructor
ResourcePlace::ResourcePlace(QString resName, int resIndex, int resReturnValue) :
    m_dice{}, m_currentPlayer{nullptr}, m_diceSum{0}, m_toolLevel{0}, m_resourcesClaimed{false}, m_total{0},
    m_resName{resName}, m_resIndex{resIndex}, m_resReturnValue{resReturnValue} {}


// Utils
void ResourcePlace::updateCalcViewHelper(int toolLevel, Game* game, Player* player) {
    m_toolLevel += toolLevel;
    int totalSum{m_diceSum+m_toolLevel};

    updateAnnounceResources(totalSum, game, player);
}

void ResourcePlace::updateAnnounceResources(int total, Game* game, Player* player) {
    PlayerBoard* playerBoard{player->getPlayerBoard()};
    QString calc{QString::number(total) + " / " + QString::number(m_resReturnValue) + " = " + QString::number(total/m_resReturnValue)};
    game->announceResources(m_dice, calc, m_resName, playerBoard->getTools()->getTools());
}

void ResourcePlace::claimResourceHelper(Game* game) {
    if (!m_resourcesClaimed) {
        PlayerBoard* playerBoard{m_currentPlayer->getPlayerBoard()};
        Resource* res{playerBoard->getResourceStock().at(m_resIndex)};
        res->increaseAmount((m_diceSum+m_toolLevel) / m_resReturnValue);
        playerBoard->updatePlayerBoard();

        m_resourcesClaimed = true;
        game->announce("Je hebt je resources gekregen.");
    }
}

Player *ResourcePlace::getPlayer() const {
    return m_currentPlayer;
}
