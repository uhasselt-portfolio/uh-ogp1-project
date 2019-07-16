#ifndef TOOLMAKERPLACE_H
#define TOOLMAKERPLACE_H

#include <QString>

#include "../Place.h"

class Worker;
class Player;
class Game;

class ToolMakerPlace : public Place {
    public:
        // Constructor
        ToolMakerPlace(QString name, int maximumWorkerAmount, Game* game);

        // Utils
        void calculateMaterials(Player* player, int currentWorkers);
};

#endif // TOOLMAKERPLACE_H
