#include "RangedResourceBuildingCard.h"
#include "../Game.h"
#include "../PlayerBoardItems/Resource.h"

// Constructor
RangedResourceBuildingCard::RangedResourceBuildingCard(int returnPoints, QString imagePath, Game* game, int min, int max) :
    BuildingCard{returnPoints, imagePath, game}, m_minimumResources{min}, m_maximumResources{max} {}

// Getters
int RangedResourceBuildingCard::getMinimumResources() const {
    return m_minimumResources;
}

int RangedResourceBuildingCard::getMaximumResources() const {
    return m_maximumResources;
}

bool RangedResourceBuildingCard::checkValidResources() const {
    return m_givenResources.size() >= m_minimumResources && m_givenResources.size() <= m_maximumResources;
}

int RangedResourceBuildingCard::getReturnPoints() const {
    int returnPoints{0};

    for(int i{0}; i < m_givenResources.size(); ++i) {
        Resource* resource{m_givenResources.at(i)};
        returnPoints += resource->getCalculationValue() * resource->getCurrentAmount();
    }

    return returnPoints;
}

