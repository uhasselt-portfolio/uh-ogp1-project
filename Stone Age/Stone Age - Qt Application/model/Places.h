#ifndef PLACES_H
#define PLACES_H

class HutPlace;
class HuntPlace;
class FieldPlace;
class RiverPlace;
class ForestPlace;
class QuarryPlace;
class ClayPitPlace;
class ToolMakerPlace;
class Place;
class BuildingCardPlace;
class CivilisationCardPlace;

#include <QVector>

class Places {
    public:
        // Constructor
        Places(HutPlace* hut, HuntPlace* hunt, FieldPlace* field, RiverPlace* river, ForestPlace* forest,
               QuarryPlace* quarry, ClayPitPlace* clayPit, ToolMakerPlace* toolMaker, QVector<BuildingCardPlace*> buildingCardPlaces,
               QVector<CivilisationCardPlace*> civilisationCardPlace);

        // Getters
        HutPlace* getHut() const;
        HuntPlace* getHunt() const;
        FieldPlace* getField() const;
        RiverPlace* getRiver() const;
        ForestPlace* getForest() const;
        QuarryPlace* getQuarry() const;
        ClayPitPlace* getClayPit() const;
        ToolMakerPlace* getToolMaker() const;

        Place* getActivePlace() const;
        Place* getLastClickedPlace() const;
        bool areEqual(Place* first, Place* second) const;
        bool isActivePlaceSet() const;

        // Setters
        void setActivePlace(Place* activePlace);
        void unsetActivePlace();
        void setLastClickedPlace(Place* place);

        // Utils
        void releaseAllWorkers();

    private:
        QVector<Place*> m_places;
        QVector<BuildingCardPlace*> m_buildingCardPlaces;
        QVector<CivilisationCardPlace*> m_civilisationCardPlaces;
        Place* m_activePlace;
        Place* m_lastClickedPlace;
};

#endif // PLACES_H
