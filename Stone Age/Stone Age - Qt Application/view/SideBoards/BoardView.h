#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QVector>

#include "../../model/Team.h"

class Game;
class ForestView;
class ClayPitView;
class QuarryView;
class RiverView;
class FieldView;
class ToolMakerView;
class HutView;
class HuntView;
class PlaceView;
class FoodMarkerView;
class BuildingCardView;
class CivilisationCardView;

class BoardView : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

    public:
        // Constructor
        BoardView(int x, int y, int h, QGraphicsScene* scene = nullptr, Game* game = nullptr);

        // Init
        void initBackground();
        void initRecoursePlaces();
        void initCardPlaces();
        void initFoodMarkers();

        // Getters
        ForestView* getForestView() const;
        ClayPitView* getClayPitView() const;
        QuarryView* getQuarryView() const;
        RiverView* getRiverView() const;
        FieldView* getFieldView() const;
        ToolMakerView* getToolMakerView() const;
        HutView* getHutView() const;
        HuntView* getHuntView() const;
        QVector<BuildingCardView*> getBuildingCardViews() const;
        QVector<CivilisationCardView*> getCivilisationCardViews() const;

        // Setters
        void moveFoodMarker(int level=1, Team team=Team::RED);
        void updateAllFoodMarkers();

    public slots:
        void r_updateFarmerLevel(int level, Team team);

    private:
        Game* m_game;
        QVector<PlaceView*> m_places;
        QVector<BuildingCardView*> m_buildingCards;
        QVector<CivilisationCardView*> m_civilisationCards;
        QVector<FoodMarkerView*> m_foodMarkers;
        ForestView* m_forest;
};

#endif // BOARDVIEW_H
