#ifndef RESOURCE_H
#define RESOURCE_H

enum class ResourceType{WOOD, BRICK, STONE, GOLD};

class Resource {
    public:
        // Constructor
        Resource();
        Resource(int calculationValue, int currentAmount, ResourceType type);
        Resource(ResourceType type, int currentAmount);

        // Getters
        int getCalculationValue() const;
        int getCurrentAmount() const;
        ResourceType getType() const;

        // Setters
        void increaseAmount(int amount);
        void decreaseAmount(int amount);
        void setAmount(int amount);

    private:
        int m_calculationValue;
        int m_currentAmount;
        ResourceType m_type;
    };

#endif // RESOURCE_H
