#ifndef DICE_H
#define DICE_H

#include <QVector>

class Dice {
    public:

        // Constructor
        Dice(int diceAmount);

        // Getters
        QVector<int> getDice() const;
        int getDiceSum() const;

        // Util
        void roll();

    private:
        int m_diceAmount;
        int m_diceSum;
        QVector<int> m_diceVector;
};

#endif // DICE_H
