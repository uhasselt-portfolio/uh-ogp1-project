#include <QDebug>

#include "BuildingCard.h"

#include "../PlayerBoardItems/Resource.h"
#include "../PlayerBoardItems/Worker.h"
#include "../Game.h"

// Constructor
BuildingCard::BuildingCard(int returnPoints, QString imagePath, Game* game)
    : m_returnPoints{returnPoints}, m_imagePath{imagePath}, m_game{game} {}

// Getters
int BuildingCard::getReturnPoints() const {
    return m_returnPoints;
}

QString BuildingCard::getImagePath() const {
    return m_imagePath;
}

// Setters
void BuildingCard::setGivenResources(QVector<Resource*> resources) {
    m_givenResources.erase(m_givenResources.begin(), m_givenResources.end());
    m_givenResources.append(resources);
}



QVector<Resource *> BuildingCard::getGivenResources() const {
    return m_givenResources;
}

QVector<int> BuildingCard::convertResources(QVector<Resource *> resources) {
    QVector<int> returnResources(4, 0);

    foreach(Resource* res, resources) {
        switch(res->getType()) {
            case ResourceType::WOOD:
                returnResources[0] = returnResources[0]+res->getCurrentAmount();
                break;
            case ResourceType::BRICK:
                returnResources[1] = returnResources[1]+res->getCurrentAmount();
                break;
            case ResourceType::STONE:
                returnResources[2] = returnResources[2]+res->getCurrentAmount();
                break;
            case ResourceType::GOLD:
                returnResources[3] = returnResources[3]+res->getCurrentAmount();
                break;
        }
    }

    return returnResources;
}

QVector<Resource *> BuildingCard::convertResourcesBack(QVector<int> resources) {
    QVector<Resource*> returnResources{};

    for (int i{0}, l{resources[0]}; i < l; ++i) {
        returnResources.append(new Resource{ResourceType::WOOD, 1});
    }
    for (int i{0}, l{resources[1]}; i < l; ++i) {
        returnResources.append(new Resource{ResourceType::BRICK, 1});
    }
    for (int i{0}, l{resources[2]}; i < l; ++i) {
        returnResources.append(new Resource{ResourceType::STONE, 1});
    }
    for (int i{0}, l{resources[3]}; i < l; ++i) {
        returnResources.append(new Resource{ResourceType::GOLD, 1});
    }

    return returnResources;
}
