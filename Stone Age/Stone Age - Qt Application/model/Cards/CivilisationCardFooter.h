#ifndef CIVILISATIONCARDFOOTER_H
#define CIVILISATIONCARDFOOTER_H

#include <QString>

class Game;

enum class BackgroundType{GRASS, SAND};
enum class CardType{
    // Grass
    HEALING, ART, WRITING, POTTERY, TIME, TRANSPORT, MUSIC, WEAVING,
    // Sand
    FOOD, TOOLS, BUILDING, WORKERS
};

class CivilisationCardFooter {
    public:
        // Constructor
        CivilisationCardFooter(BackgroundType backgroundType, CardType cardType, int amount, Game* game);

        // Getters
        CardType getCardType() const;
        int getAmountOfEntitiesOnCard() const;
        BackgroundType getBackgroundType()const;

        // Utils
        void execute();

    private:
        Game* m_game;
        BackgroundType m_backgroundType;
        CardType m_cardType;
        int m_amount;
};

#endif // CIVILISATIONCARDFOOTER_H
