#ifndef FORESTPLACE_H
#define FORESTPLACE_H

#include <QString>

#include "../Place.h"
#include "ResourcePlace.h"
#include "../../config.h"

class Worker;
class Player;
class Game;

class ForestPlace : public Place, public ResourcePlace {
    public:
        // Constructor
        ForestPlace(QString name, int maximumWorkerAmount, Game* game);

        // Utils
        void calculateMaterials(Player* player, int currentWorkers);
        void updateCalcView(Player* player, int toolLevel);
        void claimResources();
};

#endif // FORESTPLACE_H
