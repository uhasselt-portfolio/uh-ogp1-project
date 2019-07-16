#ifndef FOODTRACKER_H
#define FOODTRACKER_H


class FoodTracker {
    public:
        // Constructor
        FoodTracker(int score);

        // Getters
        int getFoodLevel() const;

        // Setters
        void increaseFoodLevel(int increaseBy = 1);
        void setFoodLevel(int amount);

    private:
        int m_level;
};

#endif // FOODTRACKER_H
