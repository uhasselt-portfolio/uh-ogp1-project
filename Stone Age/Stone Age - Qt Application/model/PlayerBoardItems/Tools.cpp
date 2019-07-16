#include "Tools.h"
#include "Tool.h"

#include <QDebug>
#include "../Game.h"
#include "../Player.h"
#include "../Players.h"
#include "../PlayerBoard.h"
#include "../GameBoard.h"
#include "../Places.h"
#include "../Place.h"

#include "../Places/RiverPlace.h"

// Constructor
Tools::Tools(QVector<Tool*> tools, Game* game) : m_tools{tools}, m_game{game} {}


// Getters
QVector<Tool *> Tools::getTools() const {
    return m_tools;
}

int Tools::getAmountOfTools() const {
    int total{0};
    for(int i{0}; i < m_tools.size(); ++i) {
        total += m_tools.at(i)->getLevel();
    }
    return total;
}


// Setters
void Tools::upgradeNextTool() {
    if (m_tools.size() < 4) {
        Tool* newTool{new Tool{INFINITE}};
        m_tools.append(newTool);
    }
    else {
        for (int i{0}, l{m_tools.size()}; i < l; ++i) {
            Tool* tool{m_tools[i]};

            if (tool->isUpgradeable()) {
                tool->upgradeLevel();
                break;
            }
        }
    }
}
void Tools::resetTools() {
    QVector<Tool*> newTools{};

    for(int i{0}, l{m_tools.size()}; i < l; ++i) {
        Tool* tool{m_tools[i]};

        tool->reset();
        if (!tool->isToolAvailable()) delete tool;
        else newTools.append(tool);
    }

    m_tools = newTools;
}

void Tools::setTools(QVector<Tool *> tools) {
    m_tools = tools;
}

void Tools::addFiniteTool(int level) {
    m_tools.append(new Tool{level, level, 1});
}


// MV
void Tools::useTool(int level) {
    foreach(Tool* tool, m_tools) {
        if (tool->getLevel() == level && !tool->isUsedThisRound()) {
            tool->use();

            Player* currentPlayer{m_game->getPlayers()->getCurrentPlayer()};
            Place* activePlace{m_game->getGameBoard()->getPlaces()->getLastClickedPlace()};

            activePlace->updateCalcView(currentPlayer, level);

            qDebug() << "@Tools.cpp - Tool Level " << level;
            break;
        }
    }

    qDebug() << m_tools;
}
