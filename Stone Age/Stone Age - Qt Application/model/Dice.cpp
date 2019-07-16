#include "Dice.h"

#include <QRandomGenerator>
#include <QDateTime>
#include <QDebug>

// Constructor
Dice::Dice(int diceAmount) : m_diceAmount{diceAmount} {}


// Getters
QVector<int> Dice::getDice() const {
    return m_diceVector;
}

int Dice::getDiceSum() const {
    return m_diceSum;
}


// Utils
void Dice::roll() {
    m_diceVector.erase(m_diceVector.begin(), m_diceVector.end());
    m_diceSum = 0;

    for (int i{0}; i < m_diceAmount; ++i) {
        QRandomGenerator dice{quint32(QDateTime::currentMSecsSinceEpoch() + i)};
        int diceNum{dice.bounded(1, 6)};

         m_diceSum+=diceNum;
         m_diceVector.append(diceNum);
    }
}
