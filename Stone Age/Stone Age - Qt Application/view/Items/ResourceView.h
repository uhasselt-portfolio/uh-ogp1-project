#ifndef RESOURCEVIEW_H
#define RESOURCEVIEW_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class BuildingCardPlace;
class CivilisationCardPlace;

class ResourceView : public QGraphicsPixmapItem {
    public:
        // Constructor
        ResourceView(int x=0, int y=0, int size=20, QString type="wood", QGraphicsItem *parent=nullptr, bool clickable = true);

        // Getters
        QString getType() const;

        // Setters
        void setBuildingCardPlace(BuildingCardPlace* place);
        void setCivilCardPlace(CivilisationCardPlace* place);

        void setClickable();
        void unsetClickable();

        // Events
        void mousePressEvent(QGraphicsSceneMouseEvent *event);

    private:
        QString m_type;
        BuildingCardPlace* m_buildingCard;
        CivilisationCardPlace* m_civilCard;
        bool m_clickable;
};

#endif // RESOURCEVIEW_H
