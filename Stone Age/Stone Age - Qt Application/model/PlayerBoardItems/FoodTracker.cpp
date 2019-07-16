#include "FoodTracker.h"

// Constructor
FoodTracker::FoodTracker(int score) : m_level{score} {}


// Getters
int FoodTracker::getFoodLevel() const {
    return m_level;
}


// Setters
void FoodTracker::increaseFoodLevel(int increaseBy) {
    m_level += increaseBy;

    if (m_level > 10)
        m_level = 10;
}

void FoodTracker::setFoodLevel(int amount) {
    m_level = amount;
}


