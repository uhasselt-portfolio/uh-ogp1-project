#include <QDebug>
#include <QFileDialog>
#include <QString>
#include "../config.h"

#include "Game.h"
#include "Seeder.h"
#include "Players.h"
#include "Player.h"
#include "GameBoard.h"
#include "Place.h"
#include "GameRoundManager.h"
#include "CardStack.h"

#include "FileHandler.h"

#include "PlayerBoard.h"
#include "./PlayerBoardItems/ScoreTracker.h"

// Constructor
Game::Game() {
    Seeder seeder{};
    m_players = seeder.loadPlayers(this);
    m_gameBoard = seeder.loadGameBoard(this);
    m_gameRoundManager = seeder.loadGameRounds(m_players, this);
}


Players* Game::getPlayers() const {
    return m_players;
}
GameBoard* Game::getGameBoard() const {
    return m_gameBoard;
}
GameRoundManager* Game::getGameRoundManager() const {
    return m_gameRoundManager;
}

bool Game::isGameFinished() const {
    for(int i{0}; i < PLAYERS_IN_GAME; ++i)
        if(m_players->getPlayer(i)->getPlayerBoard()->getScoreTracker()->getScore() >= TOTAL_SCORE)
            return true;
    return false;
}


void Game::start() {

}

void Game::stop() {

}

void Game::load() {
    QString loadPath{QFileDialog::getOpenFileName(nullptr, "Laad je spel data in.", "", "Json (*.json)")};
    if (!loadPath.isEmpty()) {
        qDebug() << loadPath;

        FileHandler fh{this};
        fh.loadGame(loadPath);
    }
}

void Game::save() {

    QString savedPath{QFileDialog::getSaveFileName(nullptr, "Bewaar je spel data.", "", "Json (*.json)")};
    FileHandler fh{this};
    fh.saveGame(savedPath);
}

void Game::updateAllPlayerBoards() {
    for(int i{0}; i < m_players->getSize(); ++i)
        m_players->getPlayer(i)->getPlayerBoard()->updatePlayerBoard();
}

void Game::announce(QString text) {
    emit s_announce(text);
}

void Game::announceResources(QVector<int> dice, QString calc, QString resType, QVector<Tool *> tools) {
    emit s_announceResources(dice, calc, resType, tools);
}

void Game::r_save() {
    qDebug() << "@Game.cpp - Saving file...";
    save();
}

void Game::r_load() {
    qDebug() << "@Game.cpp - Loading file...";
    load();
}
