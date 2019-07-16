#ifndef RANGEDRESOURCEBUILDINGCARD_H
#define RANGEDRESOURCEBUILDINGCARD_H

#include <QString>

#include "BuildingCard.h"

class Game;

class RangedResourceBuildingCard : public BuildingCard {
    public:
        // Constructor
        RangedResourceBuildingCard(int returnPoints, QString imagePath, Game* game, int min, int max);

        // Getters
        int getMinimumResources() const;
        int getMaximumResources() const;
        bool checkValidResources() const;
        int getReturnPoints() const;
        int getType() const { return 1; }

    private:
        int m_minimumResources;
        int m_maximumResources;
};

#endif // RANGEDRESOURCEBUILDINGCARD_H
