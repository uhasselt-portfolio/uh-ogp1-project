#ifndef CIVILISATIONCARD_H
#define CIVILISATIONCARD_H

#include <QString>

#include "../Team.h"

class Game;
class CivilisationCardHeader;
class CivilisationCardFooter;


class CivilisationCard {
    public:
        // Constructor
        CivilisationCard(QString imagePath, CivilisationCardHeader* cch, CivilisationCardFooter* ccf,  Game* game);

        // Getters
        CivilisationCardHeader *getCardHeader() const;
        CivilisationCardFooter* getCardFooter() const;
        QString getImagePath() const;

        // Utils
        void executeHeader();

    private:
        Game* m_game;
        CivilisationCardHeader* m_cardHeader;
        CivilisationCardFooter* m_cardFooter;
        QString m_imagePath;
};

#endif // CIVILISATIONCARD_H
