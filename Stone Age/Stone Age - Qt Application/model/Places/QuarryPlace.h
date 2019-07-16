#ifndef QUARRYPLACE_H
#define QUARRYPLACE_H

#include <QString>

#include "../Place.h"
#include "ResourcePlace.h"

class Worker;
class Player;
class Game;

class QuarryPlace : public Place, public ResourcePlace {
    public:
        // Constructor
        QuarryPlace(QString name, int maximumWorkerAmount, Game* game);

        // Utils
        void calculateMaterials(Player* player, int currentWorkers);
        void updateCalcView(Player* player, int toolLevel);
        void claimResources();
};

#endif // QUARRYPLACE_H
