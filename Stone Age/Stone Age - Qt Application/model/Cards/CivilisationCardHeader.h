#ifndef CIVILISATIONCARDHEADER_H
#define CIVILISATIONCARDHEADER_H

#include <QString>

class Game;

enum class HeaderType {FOOD_SUPPLY, RESOURCE_GOLD, RESOURCE_STONE, RESOURCE_BRICK, POINTS, TOOL_INFINITE, FOOD_TRACKER, TOOL_FINITE};

class CivilisationCardHeader {
    public:
        // Constructor
        CivilisationCardHeader(HeaderType type, int amount, Game* game);

        // Utils
        void execute();

        // Getters
        HeaderType getType() const;
        int getAmount() const;

    private:
        Game* m_game;
        HeaderType m_type;
        int m_amount;
};


#endif // CIVILISATIONCARDHEADER_H
