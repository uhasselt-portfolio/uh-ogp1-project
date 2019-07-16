#ifndef HUNTPLACE_H
#define HUNTPLACE_H

#include <QString>

#include "../Place.h"
#include "ResourcePlace.h"

class Worker;
class Player;
class Game;

class HuntPlace : public Place, public ResourcePlace {
    public:
        // Consturctor
        HuntPlace(QString name, int maximumWorkerAmount, Game* game);

        // Utils
        void calculateMaterials(Player* player, int currentWorkers);
        void updateCalcView(Player* player, int toolLevel);
        void claimResources();
};

#endif // HUNTPLACE_H
