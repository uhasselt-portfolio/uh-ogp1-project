#include "CivilisationCardFooter.h"
#include "../Game.h"

CivilisationCardFooter::CivilisationCardFooter(BackgroundType backgroundType, CardType cardType, int amount, Game* game)
    : m_backgroundType{backgroundType}, m_cardType{cardType}, m_amount{amount}, m_game{game} {

}

CardType CivilisationCardFooter::getCardType() const {
    return m_cardType;
}

int CivilisationCardFooter::getAmountOfEntitiesOnCard() const {
    return m_amount;
}

BackgroundType CivilisationCardFooter::getBackgroundType() const {
    return m_backgroundType;
}

// Utils
void CivilisationCardFooter::execute() {

}
