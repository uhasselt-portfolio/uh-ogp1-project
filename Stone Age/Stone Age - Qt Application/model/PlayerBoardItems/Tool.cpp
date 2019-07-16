#include "Tool.h"

// Constructor
Tool::Tool(int useableTimes) : m_currentLevel{1}, m_maximumLevel{4}, m_useableTimes{useableTimes}, m_usedThisRound{false} {}
Tool::Tool(int level, int maxLevel, int useableTimes) : m_currentLevel{level}, m_maximumLevel{maxLevel}, m_useableTimes{useableTimes}, m_usedThisRound{false} {}


// Getters
int Tool::getLevel() const {
    return m_currentLevel;
}
int Tool::getMaximumLevel() const {
    return m_maximumLevel;
}
int Tool::getUseableTimes() const {
    return m_useableTimes;
}

bool Tool::isUsedThisRound() const {
    return m_usedThisRound;
}
bool Tool::isToolAvailable() const {
    if (m_useableTimes == INFINITE)
        return true;
    return m_useableTimes > 0;
}
bool Tool::isUpgradeable() const {
    if (m_useableTimes == INFINITE)
        return m_currentLevel < m_maximumLevel;
    return false;

}


// Setters
void Tool::increaseLevel(int increaseBy) {
    m_currentLevel += increaseBy;
}
void Tool::upgradeLevel() {
    increaseLevel(1);
}
void Tool::use() {
    m_usedThisRound = true;

    if (m_useableTimes != INFINITE)
        --m_useableTimes;
}
void Tool::reset() {
    m_usedThisRound = false;
}
