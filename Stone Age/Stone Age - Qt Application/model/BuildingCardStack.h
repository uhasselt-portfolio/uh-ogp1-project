#ifndef BUILDINGCARDSTACK_H
#define BUILDINGCARDSTACK_H

#include <QVector>

class BuildingCard;

class BuildingCardStack {
    public:
        // Constructor
        BuildingCardStack(QVector<BuildingCard*> buildingCards);

        // Getters
        BuildingCard* getBuildingCardFromStack(int index);
        QVector<QVector<BuildingCard*>> getBuildCardStacks();
        QVector<int> getBuildingStackIndexes() const;

        // Setters
        void setBuildingCardStacks(QVector<QVector<BuildingCard*>> stacks);
        void setBuildingStackIndexes(QVector<int> indexes);

        // Utils
        bool isACardStackEmpty() const;
        void updateStackIndex(int index);

    private:
        QVector<QVector<BuildingCard*>> m_buildingCardStack;
        QVector<int> m_currentStackIndex;
};



#endif // BUILDINGCARDSTACK_H
