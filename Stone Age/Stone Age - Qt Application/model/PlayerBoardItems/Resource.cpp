#include "Resource.h"
#include "../../config.h"


// Constructor
Resource::Resource() {}

Resource::Resource(int calculationValue, int currentAmount, ResourceType type)
    : m_calculationValue{calculationValue}, m_currentAmount{currentAmount}, m_type{type} {}

Resource::Resource(ResourceType type, int currentAmount) : m_currentAmount{currentAmount}, m_type{type} {
    switch(type) {
        case ResourceType::WOOD:
            m_calculationValue = FOREST_RESOURCE_RETURN;
            break;
        case ResourceType::STONE:
            m_calculationValue = QUARRY_RESOURCE_RETURN;
            break;
        case ResourceType::BRICK:
            m_calculationValue = CLAYPIT_RESOURCE_RETURN;
            break;
        case ResourceType::GOLD:
            m_calculationValue = RIVER_RESOURCE_RETURN;
            break;
    }
}

// Getters
int Resource::getCalculationValue() const {
    return m_calculationValue;
}

int Resource::getCurrentAmount() const {
    return m_currentAmount;
}

ResourceType Resource::getType() const {
    return m_type;
}

// Utils
void Resource::increaseAmount(int amount) {

    m_currentAmount += amount;
}

void Resource::decreaseAmount(int amount) {
    m_currentAmount -= amount;
}

void Resource::setAmount(int amount) {
    m_currentAmount = amount;
}
