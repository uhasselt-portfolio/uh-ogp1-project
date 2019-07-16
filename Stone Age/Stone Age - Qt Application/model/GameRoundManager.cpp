#include <QDebug>

#include "GameRoundManager.h"
#include "../config.h"

#include "Players.h"
#include "PlayerBoard.h"
#include "PlayerBoardItems/Workers.h"
#include "PlayerBoardItems/Food.h"
#include "PlayerBoardItems/FoodTracker.h"
#include "PlayerBoardItems/ScoreTracker.h"
#include "PlayerBoardItems/Tools.h"
#include "PlayerBoardItems/Tool.h"

#include "FileHandler.h"

#include "Game.h"
#include "GameBoard.h"
#include "Places.h"
#include "Player.h"
#include "PlacedCards.h"
#include "CardStack.h"
#include "BuildingCardStack.h"

// Constructor
GameRoundManager::GameRoundManager(Players* players, int round, int phase, int firstPlayerIndex, Game* game)
    : m_players{players}, m_round{round}, m_phase{phase}, m_firstPlayerIndex{firstPlayerIndex}, m_game{game}, m_gameFinished{false} {
}

// Utils
void GameRoundManager::nextGameRound() {
   PlayerBoard* playerBoard{m_game->getPlayers()->getCurrentPlayer()->getPlayerBoard()};

    if(m_phase == 1) {
        if(m_game->getPlayers()->usedAllWorkers())
            nextPhase();
        else if(playerBoard->getWorkers()->noWorkersAvailable())
            nextRound();
        else if(playerBoard->getWorkers()->hasPlacedWorkerThisRound())
            nextRound();
    } else if(m_phase == 2) {
        if(m_round == TOTAL_ROUNDS) {
            nextPhase();
        } else
            nextRound();
    } else if (m_phase == 3) {

        m_game->getGameBoard()->getPlaces()->releaseAllWorkers();

        for(int i{0}; i < m_game->getPlayers()->getSize(); ++i) {
            m_game->getPlayers()->getPlayer(i)->getPlayerBoard()->getWorkers()->feed();
            m_game->getPlayers()->getPlayer(i)->getPlayerBoard()->updatePlayerBoard();
            m_game->getPlayers()->getPlayer(i)->getPlayerBoard()->getTools()->resetTools();
        }

        m_game->getGameBoard()->getPlacedCards()->refillCards();

//        if(m_gameFinished || m_game->getGameBoard()->getCardStack()->getBuildingCardStack()->isACardStackEmpty()) {
//            emit s_endGame();
//        } else if(m_game->getGameBoard()->getPlacedCards()->isCivilisationCardStackEmpty()) {
//            m_gameFinished = true;
//        }

//        FileHandler* fh{new FileHandler{m_game}};
//        fh->saveGame();

        nextPhase();
    }

    // Skipped to the next player

    qDebug() << "Round: " << m_round;
    qDebug() << "Phase: " << m_phase;

    m_game->getPlayers()->deActivateAll();
    m_game->getPlayers()->getCurrentPlayer()->getPlayerBoard()->setActive();
    m_game->getPlayers()->updateBuildingCardInventory();
    m_game->getPlayers()->updateCivilisationCardInventory();

    // Skip if player has no workers
    if(m_phase == 1) {
        if(m_game->getPlayers()->getCurrentPlayer()->getPlayerBoard()->getWorkers()->noWorkersAvailable()) {
            nextGameRound();
        }
    }
}

void GameRoundManager::updateFirstPlayer() {
    if(m_firstPlayerIndex + 1 % TOTAL_ROUNDS == 0) {
        m_firstPlayerIndex = 0;
    }
    else {
        m_firstPlayerIndex++;
    }
}

bool GameRoundManager::isFinalRoundActivated() const {
    m_game->getGameBoard()->getPlacedCards()->refillCards();
    return m_game->getGameBoard()->getCardStack()->getBuildingCardStack()->isACardStackEmpty() ||
            m_game->getGameBoard()->getPlacedCards()->isCivilisationCardStackEmpty();
}


// Getters
int GameRoundManager::getRound() const {
    return m_round;
}

int GameRoundManager::getPhase() const {
    return m_phase;
}

int GameRoundManager::getFirstPlayerIndex() const {
    return m_firstPlayerIndex;
}

void GameRoundManager::setRound(int round) {
    m_round = round;
}

void GameRoundManager::setPhase(int phase) {
    m_phase = phase;
}

void GameRoundManager::setFirstPlayerIndex(int index) {
    m_firstPlayerIndex = index;
}

// Setters
void GameRoundManager::nextRound() {
    if(m_round % TOTAL_ROUNDS == 0) {
        m_round = 1;
        m_game->getPlayers()->unsetWorkersPlacement();
    } else {
        // Increase round
        ++m_round;

        // Check if player has workers
        // Otherwise skip this player and go to the next
        if(m_phase == 1) {
            Workers* playerWorkers{m_game->getPlayers()->getCurrentPlayer()->getPlayerBoard()->getWorkers()};
            if(playerWorkers->getAvailableWorkers().size() == 0)
                nextRound();
        }
    }

    // Unset active place
    m_game->getGameBoard()->getPlaces()->unsetActivePlace();
}
void GameRoundManager::nextPhase() {
    if(m_phase % TOTAL_PHASES == 0) {
        m_phase = 1;
        updateFirstPlayer();
    }
    else {
        ++m_phase;
    }
    m_round = 1;
}


