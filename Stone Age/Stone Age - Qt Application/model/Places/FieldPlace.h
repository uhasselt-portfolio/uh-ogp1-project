#ifndef FIELDPLACE_H
#define FIELDPLACE_H

#include <QString>

#include "../Place.h"

class Worker;
class Player;
class Game;

class FieldPlace : public Place {
    public:
        // Constructor
        FieldPlace(QString name, int maximumWorkerAmount, Game* game);

        // Utils
        void calculateMaterials(Player* player, int currentWorkers);
};

#endif // FIELDPLACE_H
