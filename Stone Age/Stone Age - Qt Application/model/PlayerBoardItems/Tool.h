#ifndef TOOL_H
#define TOOL_H

#include "../../config.h"

class Tool {
    public:
        // Constructor
        Tool(int useableTimes = INFINITE);
        Tool (int level, int maxLevel, int useableTimes = INFINITE);

        // Getters
        int getLevel() const;
        int getMaximumLevel() const;
        int getUseableTimes() const;

        bool isUsedThisRound() const;
        bool isToolAvailable() const;
        bool isUpgradeable() const;

        // Setters
        void increaseLevel(int increaseBy = 1);
        void upgradeLevel();
        void use();
        void reset();

    private:
        int m_currentLevel;
        int m_maximumLevel;
        int m_useableTimes;
        bool m_usedThisRound;
};

#endif // TOOL_H
