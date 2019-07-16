#ifndef FOOD_H
#define FOOD_H


class Food {
    public:
        // Constructor
        Food(int amount);

        // Getters
        int getFoodSupply() const;

        // Setters
        void decreaseFoodSupply(int decreaseBy);
        void increaseFoodSupply(int increaseBy);
        void setFoodSupply(int amount);

    private:
        int m_currentAmount;
};

#endif // FOOD_H
