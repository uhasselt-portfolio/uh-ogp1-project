#ifndef PLAYERBOARD_H
#define PLAYERBOARD_H

#include <QObject>
#include <QVector>
#include <QHash>

#include "Cards/CivilisationCardFooter.h"

class Food;
class ScoreTracker;
class FoodTracker;
class Resource;
class BuildingCard;
class CivilisationCard;
class Tools;
class Workers;

class PlayerBoard : public QObject {
    Q_OBJECT
    public:
        // Constructor
        PlayerBoard(Workers* workers, Food* food, ScoreTracker* scoreTracker,
                    FoodTracker* foodTracker, QVector<Resource*> resourceStock,
                    QVector<BuildingCard*> collectedBuildingCards,
                    QVector<CivilisationCard*> collectedCivilisationCards,
                    Tools* tools);

        // Getters
        Workers* getWorkers() const;
        Food* getFoodStock() const;
        ScoreTracker* getScoreTracker() const;
        FoodTracker* getFoodTracker() const;
        QVector<Resource*> getResourceStock() const;
        QVector<BuildingCard*> getCollectedBuildingCards() const;
        QVector<CivilisationCard*> getCollectedCivilisationCards() const;
        Tools* getTools() const;

        int getCivlisationCardScore();

        // Setters
        void setCollectedBuildingCards(QVector<BuildingCard*> cards);
        void setCollectedCivilisationCards(QVector<CivilisationCard*> cards);

        // Utils
        void updatePlayerBoard();
        void setActive();
        void unsetActive();

        void collectBuildingCard(BuildingCard* buildingCard);
        void collectCivilisationCard(CivilisationCard* civilisationCard);

    signals:
        void s_setActiveState(bool active);
        void s_updatePlayerBoard(QString worker, QString food, QString score, QString wood, QString stone, QString brick, QString gold, Tools* tools);

    private:
        QHash<int, int> loadCollectedSandCivilisationCards();
        QHash<int, int> loadCollectedGrassCivilisationCards();

        int getPointsCollectedSandCivilisationCards(QHash<int,int> sandCardTypesCollected);
        int getPointsCollectedGrassCivilisationCards(QHash<int,int> grassCardTypesCollected);

        Workers* m_workers;
        Food* m_foodStock;
        ScoreTracker* m_scoreTracker;
        FoodTracker* m_foodTracker;
        QVector<Resource*> m_resourceStock;
        QVector<BuildingCard*> m_collectedBuildingCards;
        QVector<CivilisationCard*> m_collectedCivilisationCard;
        Tools* m_tools;
};



#endif // PLAYERBOARD_H
