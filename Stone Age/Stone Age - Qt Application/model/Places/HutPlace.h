#ifndef HUTPLACE_H
#define HUTPLACE_H

#include <QString>

#include "../Place.h"

class Worker;
class Player;
class Game;

class HutPlace : public Place {
    public:
        // Constructor
        HutPlace(QString name, int maximumWorkerAmount, Game* game);

        // Utils
        void calculateMaterials(Player* player, int currentWorkers) override;
};

#endif // HUTPLACE_H
