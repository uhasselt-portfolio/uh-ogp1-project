#include "Food.h"

// Constructor
Food::Food(int amount) : m_currentAmount{amount} {}


// Getters
int Food::getFoodSupply() const {
    return m_currentAmount;
}


// Setters
void Food::decreaseFoodSupply(int decreaseBy) {
    if(m_currentAmount - decreaseBy <= 0)
        m_currentAmount = 0;
    else
        m_currentAmount -= decreaseBy;
}
void Food::increaseFoodSupply(int increaseBy) {
    m_currentAmount += increaseBy;
}

void Food::setFoodSupply(int amount) {
    m_currentAmount = amount;
}



