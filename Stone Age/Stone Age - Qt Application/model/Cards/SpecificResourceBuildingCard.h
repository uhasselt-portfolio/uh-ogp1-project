#ifndef SPECIFICRESOURCEBUILDINGCARD_H
#define SPECIFICRESOURCEBUILDINGCARD_H

#include <QVector>

#include "BuildingCard.h"

class Resource;
class Game;

class SpecificResourceBuildingCard : public BuildingCard {
    public:
        // Constructor
        SpecificResourceBuildingCard(int returnPoints, QString imagePath, QVector<Resource*> requiredResources, Game* game);

        // Getters
        QVector<Resource*> getRequiredResources() const;

        // Abstract
        bool checkValidResources() const;
        int getReturnPoints() const;
        int getType() const { return 0; }

    private:
        QVector<Resource*> m_requiredResources;
};

#endif // SPECIFICRESOURCEBUILDINGCARD_H
