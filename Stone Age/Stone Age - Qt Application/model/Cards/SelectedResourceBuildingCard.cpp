#include "SelectedResourceBuildingCard.h"
#include "../Game.h"
#include "../PlayerBoardItems/Resource.h"

SelectedResourceBuildingCard::SelectedResourceBuildingCard(int returnPoints, QString imagePath, Game* game, int numKinds, int total) :
    BuildingCard{returnPoints, imagePath, game}, m_numberOfKinds{numKinds}, m_totalAmount{total} {}

int SelectedResourceBuildingCard::getNumberOfKinds() const {
    return m_numberOfKinds;
}

int SelectedResourceBuildingCard::getTotalAmount() const {
    return m_totalAmount;
}

bool SelectedResourceBuildingCard::checkValidResources() const {
    // Calc unique resource type
    int unique{0}, total{0};
    foreach (int res, BuildingCard::convertResources(m_givenResources)) {
        total += res;
        if (res != 0)
            ++unique;
    }

    return (unique == m_numberOfKinds && total == m_totalAmount);
}

int SelectedResourceBuildingCard::getReturnPoints() const {
    int returnPoints{0};

    for(int i{0}; i < m_givenResources.size(); ++i) {
        Resource* resource{m_givenResources.at(i)};
        returnPoints += resource->getCalculationValue() * resource->getCurrentAmount();
    }

    return returnPoints;}
