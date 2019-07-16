#ifndef SELECTEDRESOURCEBUILDINGCARD_H
#define SELECTEDRESOURCEBUILDINGCARD_H

#include "BuildingCard.h"

class Game;

class SelectedResourceBuildingCard : public BuildingCard {
    public:
        // Constructor
        SelectedResourceBuildingCard(int returnPoints, QString imagePath, Game* game, int numKinds, int total);

        // Getters
        int getNumberOfKinds() const;
        int getTotalAmount() const;

        // Abstract
        bool checkValidResources() const;
        int getReturnPoints() const;
        int getType() const { return 2; }

    private:
        int m_numberOfKinds;
        int m_totalAmount;
};

#endif // SELECTEDRESOURCEBUILDINGCARD_H
