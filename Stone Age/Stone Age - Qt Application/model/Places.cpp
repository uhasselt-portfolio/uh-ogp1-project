#include "Places.h"
#include "Place.h"
#include "Places/ClayPitPlace.h"
#include "Places/HuntPlace.h"
#include "Places/FieldPlace.h"
#include "Places/RiverPlace.h"
#include "Places/ForestPlace.h"
#include "Places/QuarryPlace.h"
#include "Places/ClayPitPlace.h"
#include "Places/ToolMakerPlace.h"
#include "Places/HutPlace.h"
#include "Places/BuildingCardPlace.h"
#include "Places/CivilisationCardPlace.h"

// Constructor
Places::Places(HutPlace* hut, HuntPlace* hunt, FieldPlace* field, RiverPlace* river, ForestPlace* forest, QuarryPlace* quarry, ClayPitPlace* clayPit,
               ToolMakerPlace* toolMaker, QVector<BuildingCardPlace*> buildingCardPlaces, QVector<CivilisationCardPlace*> civilisationCardPlace) :
    m_buildingCardPlaces{buildingCardPlaces}, m_civilisationCardPlaces{civilisationCardPlace}, m_activePlace{nullptr}, m_lastClickedPlace{nullptr} {

    m_places.append(hut); // 0
    m_places.append(hunt); // 1
    m_places.append(field); // 2
    m_places.append(river); // 3
    m_places.append(forest); // 4
    m_places.append(quarry); // 5
    m_places.append(clayPit); // 6
    m_places.append(toolMaker); // 7
}


// Getters
HutPlace* Places::getHut() const {
    return reinterpret_cast<HutPlace*>(m_places.at(0));
}
HuntPlace* Places::getHunt() const {
    return reinterpret_cast<HuntPlace*>(m_places.at(1));
}
FieldPlace* Places::getField() const {
    return reinterpret_cast<FieldPlace*>(m_places.at(2));
}
RiverPlace* Places::getRiver() const {
    return reinterpret_cast<RiverPlace*>(m_places.at(3));
}
ForestPlace* Places::getForest() const {
    return reinterpret_cast<ForestPlace*>(m_places.at(4));
}
QuarryPlace* Places::getQuarry() const {
    return reinterpret_cast<QuarryPlace*>(m_places.at(5));
}
ClayPitPlace* Places::getClayPit() const {
    return reinterpret_cast<ClayPitPlace*>(m_places.at(6));
}
ToolMakerPlace* Places::getToolMaker() const {
    return reinterpret_cast<ToolMakerPlace*>(m_places.at(7));
}

Place* Places::getActivePlace() const {
    return m_activePlace;
}

Place *Places::getLastClickedPlace() const {
    return m_lastClickedPlace;
}
bool Places::areEqual(Place *first, Place *second) const {
    return first == second;
}
bool Places::isActivePlaceSet() const {
    return m_activePlace != nullptr;
}


// Setters
void Places::setActivePlace(Place *activePlace) {
    m_activePlace = activePlace;
}
void Places::unsetActivePlace() {
    m_activePlace = nullptr;
}

void Places::setLastClickedPlace(Place *place) {
    m_lastClickedPlace = place;
}


// Utils
void Places::releaseAllWorkers() {
    for(int i{0}; i < m_places.size(); ++i) {
        m_places.at(i)->releaseWorkers();
    }

    for(int i{0}; i < m_buildingCardPlaces.size(); ++i) {
        m_buildingCardPlaces.at(i)->releaseWorkers();
    }

    for(int i{0}; i < m_civilisationCardPlaces.size(); ++i) {
        m_civilisationCardPlaces.at(i)->releaseWorkers();
    }
}
