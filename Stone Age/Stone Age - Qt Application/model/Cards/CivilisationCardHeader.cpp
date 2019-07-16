#include "CivilisationCardHeader.h"
#include "../../config.h"

#include "../Game.h"
#include "../Player.h"
#include "../Players.h"
#include "../PlayerBoard.h"
#include "../PlayerBoardItems/Food.h"
#include "../PlayerBoardItems/Resource.h"
#include "../PlayerBoardItems/ScoreTracker.h"
#include "../PlayerBoardItems/FoodTracker.h"
#include "../PlayerBoardItems/Tools.h"
#include "../PlayerBoardItems/Tool.h"

// Constructor
CivilisationCardHeader::CivilisationCardHeader(HeaderType type, int amount, Game* game)
    : m_game{game}, m_type{type}, m_amount{amount} {
}

// Utils
void CivilisationCardHeader::execute() {
    PlayerBoard* playerBoard{m_game->getPlayers()->getCurrentPlayer()->getPlayerBoard()};
    switch(m_type) {
    case HeaderType::FOOD_SUPPLY:
        playerBoard->getFoodStock()->increaseFoodSupply(m_amount);
        break;
    case HeaderType::RESOURCE_STONE:
        playerBoard->getResourceStock().at(STONE_RESOURCE)->increaseAmount(m_amount);
        break;
    case HeaderType::RESOURCE_GOLD:
        playerBoard->getResourceStock().at(GOLD_RESOURCE)->increaseAmount(m_amount);
        break;
    case HeaderType::RESOURCE_BRICK:
        playerBoard->getResourceStock().at(BRICK_RESOURCE)->increaseAmount(m_amount);
        break;
    case HeaderType::POINTS:
        playerBoard->getScoreTracker()->increaseScore(m_amount);
        break;
    case HeaderType::TOOL_INFINITE:
        playerBoard->getTools()->addFiniteTool(m_amount);
        break;
    case HeaderType::FOOD_TRACKER:
        playerBoard->getFoodTracker()->increaseFoodLevel(m_amount);
        break;
    case HeaderType::TOOL_FINITE:
        playerBoard->getTools()->upgradeNextTool();
        break;
    }
}


// Getters
HeaderType CivilisationCardHeader::getType() const {
    return m_type;
}

int CivilisationCardHeader::getAmount() const {
    return m_amount;
}
