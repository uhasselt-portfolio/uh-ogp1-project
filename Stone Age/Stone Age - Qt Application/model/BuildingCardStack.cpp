#include "BuildingCardStack.h"
#include "../config.h"

#include "Cards/BuildingCard.h"

BuildingCardStack::BuildingCardStack(QVector<BuildingCard*> bigBuildingCards) {
    for(int i{0}; i < CARD_AMOUNT_ON_BOARD; ++i) {
        QVector<BuildingCard*> smallBuildingCardStack{};
        for(int j{0}; j < BUILDING_CARDS_ON_STACK; ++j) {
            int index{(i * CARD_AMOUNT_ON_BOARD) + j};
            smallBuildingCardStack.append(bigBuildingCards.at(index));
        }
        m_buildingCardStack.append(smallBuildingCardStack);
    }

    m_currentStackIndex = {0,0,0,0};
}

BuildingCard* BuildingCardStack::getBuildingCardFromStack(int index) {
    int currentIndex{m_currentStackIndex.at(index)};
    updateStackIndex(index);
    return m_buildingCardStack.at(index).at(currentIndex);
}

QVector<int> BuildingCardStack::getBuildingStackIndexes() const {
    return m_currentStackIndex;
}

QVector<QVector<BuildingCard *> > BuildingCardStack::getBuildCardStacks() {
    return m_buildingCardStack;
}

void BuildingCardStack::setBuildingCardStacks(QVector<QVector<BuildingCard *> > stacks) {
    m_buildingCardStack = stacks;
}


void BuildingCardStack::setBuildingStackIndexes(QVector<int> indexes) {
    m_currentStackIndex = indexes;
}



bool BuildingCardStack::isACardStackEmpty() const {
    for(int i{0}; i < m_buildingCardStack.size(); ++i)
        if(m_buildingCardStack.at(i).size() <= 0)
            return true;
    return false;
}

void BuildingCardStack::updateStackIndex(int index) {
    m_currentStackIndex[index] = m_currentStackIndex[index] + 1;
}
