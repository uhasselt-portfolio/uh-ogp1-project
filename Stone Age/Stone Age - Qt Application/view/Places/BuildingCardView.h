#ifndef BUILDINGVIEW_H
#define BUILDINGVIEW_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>

#include "PlaceView.h"

class Game;
class Place;
class BuildingCardPlace;
class CardView;

class BuildingCardView : public PlaceView {
    public:
        // Constructor
        BuildingCardView(int x, int y, int w, int h, BuildingCardPlace* buildingCardPlace, QGraphicsItem *parent = nullptr, Game* game = nullptr, Place* place = nullptr);

        // Getter
        CardView* getCard() const;

        // Events
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    public slots:
        void r_removeBuildingCardView();
        void r_addBuildingCardView(QString imageName);

    private:
        BuildingCardPlace* m_buildingCardPlace;
};

#endif // BUILDINGVIEW_H
