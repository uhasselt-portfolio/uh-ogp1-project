#ifndef RIVERPLACE_H
#define RIVERPLACE_H

#include <QString>

#include "../Place.h"
#include "ResourcePlace.h"

class Worker;
class Player;
class Game;

class RiverPlace : public Place, public ResourcePlace {
    public:
        // Constructor
        RiverPlace(QString name, int maximumWorkerAmount, Game* game);

        // Utils
        void calculateMaterials(Player* player, int currentWorkers);
        void updateCalcView(Player* player, int toolLevel);
        void claimResources();
};

#endif // RIVERPLACE_H
