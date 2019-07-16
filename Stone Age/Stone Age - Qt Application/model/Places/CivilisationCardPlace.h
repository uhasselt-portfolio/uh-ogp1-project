#ifndef CIVILISATIONCARDPLACE_H
#define CIVILISATIONCARDPLACE_H

#include <QString>

#include "../Place.h"

class CivilisationCard;
class BuildingCardPlace;
class Game;


class CivilisationCardPlace : public Place {
    Q_OBJECT
    public:
        // Constructor
        CivilisationCardPlace(CivilisationCard* civilisationCard, Game *game, int resourceAmount = 1);

        // Getters
        CivilisationCard* getCivilisationCard() const;

        // Setters
        void setCivilisationCard(CivilisationCard* civlisationCard);
        void resetTempResources();
        void addTempResources(int wood, int brick, int stone, int gold);
        void removeTempResources(int wood, int brick, int stone, int gold);
        void addTempResources(QVector<int> resources);

        // Utils
        void collect();
        void pay();
        void addCardView(QString imageName);

    signals:
        void s_removeCivlisationCardView();
        void s_addCivilisationCardView(QString imageName);
        void s_announcePayResources(BuildingCardPlace* bPlace, CivilisationCardPlace* cPlace, QVector<int> resources, bool changeable = true);

    private:
        CivilisationCard* m_civilisationCard;
        QVector<int> m_tempResources;
        int m_resourceAmount;
};

#endif // CIVILISATIONCARDPLACE_H
