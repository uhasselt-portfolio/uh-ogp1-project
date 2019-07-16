#include "CivilisationCard.h"

#include "../PlayerBoardItems/Worker.h"
#include "../Game.h"
#include "CivilisationCardHeader.h"
#include "CivilisationCardFooter.h"

// Constructor
CivilisationCard::CivilisationCard(QString imagePath, CivilisationCardHeader* cch, CivilisationCardFooter* ccf, Game* game)
    : m_imagePath{imagePath}, m_cardHeader{cch}, m_cardFooter{ccf}, m_game{game}{

}

CivilisationCardHeader *CivilisationCard::getCardHeader() const {
    return m_cardHeader;
}

CivilisationCardFooter *CivilisationCard::getCardFooter() const {
    return m_cardFooter;
}

QString CivilisationCard::getImagePath() const {
    return m_imagePath;
}

// Utils
void CivilisationCard::executeHeader() {
    m_cardHeader->execute();
}
