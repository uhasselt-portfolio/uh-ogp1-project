#ifndef BUILDINGCARDPLACE_H
#define BUILDINGCARDPLACE_H

#include <QString>
#include <QVector>

#include "../Place.h"
#include "../Team.h"

class BuildingCard;
class CivilisationCardPlace;
class Game;

class BuildingCardPlace : public Place {
    Q_OBJECT
    public:
        // Constructor
        BuildingCardPlace(BuildingCard* buildingCard, Game* game);

        // Getters
        BuildingCard* getBuildingCard() const;

        // Setter
        void setBuildingCard(BuildingCard* buildingCard);
        void resetTempResources();
        void addTempResources(int wood, int brick, int stone, int gold);
        void removeTempResources(int wood, int brick, int stone, int gold);
        void addTempResources(QVector<int> resources);

        // Interaction (visuals)
        void collect();
        void pay();
        void addCardView(QString imageName);

    signals:
        void s_removeBuildingCardView();
        void s_addBuildingCardView(QString imageName);
        void s_announcePayResources(BuildingCardPlace* bPlace, CivilisationCardPlace* cPlace, QVector<int> resources, bool changeable = true);

    private:
        BuildingCard* m_buildingCard;
        QVector<int> m_tempResources;
};

#endif // BUILDINGCARDPLACE_H
