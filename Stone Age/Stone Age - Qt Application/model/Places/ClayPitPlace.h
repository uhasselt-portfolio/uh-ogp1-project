#ifndef CLAYPITPLACE_H
#define CLAYPITPLACE_H

#include <QString>

#include "../Place.h"
#include "ResourcePlace.h"

class Worker;
class Player;
class Game;

class ClayPitPlace : public Place, public ResourcePlace {
    public:
        // Constructor
        ClayPitPlace(QString name, int maximumWorkerAmount, Game* game);

        // Utils
        void calculateMaterials(Player* player, int currentWorkers);
        void updateCalcView(Player* player, int toolLevel);
        void claimResources();
};

#endif // CLAYPITPLACE_H
