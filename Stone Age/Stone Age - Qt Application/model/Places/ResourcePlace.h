#ifndef RESOURCEPLACE_H
#define RESOURCEPLACE_H

#include <QVector>
#include "../../config.h"

class Game;
class Player;

class ResourcePlace {
    public:
        ResourcePlace(QString resName="wood", int resIndex = WOOD_RESOURCE, int resReturnValue = FOREST_RESOURCE_RETURN);

    protected:
        QVector<int> m_dice;
        Player* m_currentPlayer;
        int m_diceSum;
        int m_toolLevel;
        bool m_resourcesClaimed;
        int m_total;

        QString m_resName;
        int m_resIndex;
        int m_resReturnValue;

        void updateCalcViewHelper(int toolLevel, Game* game, Player* player);
        void updateAnnounceResources(int total, Game* game, Player* player);
        void claimResourceHelper(Game* game);

        Player* getPlayer() const;
};


#endif // RESOURCEPLACE_H
