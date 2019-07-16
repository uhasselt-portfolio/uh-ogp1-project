#ifndef CARDSTACK_H
#define CARDSTACK_H

#include <Qvector>

class BuildingCardStack;
class BuildingCard;
class CivilisationCard;
class Game;

class CardStack {
    public:
        // Constructor
        CardStack(QVector<BuildingCard*> buildingCards, QVector<CivilisationCard*> civilisationCards, int currentBuildingCardIndex, int currentCivilisationCardIndex);

        // Utils
        void shuffle();

        // Getters
        BuildingCardStack* getBuildingCardStack();
        CivilisationCard* getNextCivilisationCard();
        QVector<CivilisationCard*> getCivilCardStack();
        int getCivilCardIndex() const;

        // Setters
        void setCivilCards(QVector<CivilisationCard*> cards);
        void setCivilCardIndex(int index);

    private:
        BuildingCardStack* m_buildingCardStack;
        QVector<CivilisationCard*> m_civilisationCards;
        int m_currentBuildingCardIndex;
        int m_currentCivilisationCardIndex;

};

#endif // CARDSTACK_H
