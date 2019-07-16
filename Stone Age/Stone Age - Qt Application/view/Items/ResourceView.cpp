#include <qDebug>
#include <QGraphicsSceneMouseEvent>

#include "ResourceView.h"
#include "../../config.h"
#include "../../model/Place.h"
#include "../../model/Places/BuildingCardPlace.h"
#include "../../model/Places/CivilisationCardPlace.h"
#include "../../model/Places.h"

// Constructor
ResourceView::ResourceView(int x, int y, int size, QString type, QGraphicsItem *parent, bool clickable) :
    QGraphicsPixmapItem{parent}, m_type{type}, m_buildingCard{}, m_clickable{clickable} {
    setPos(x*SCALE, y*SCALE);


    type = (type == "food") ? "food.gif" : type+".png";
    setPixmap(QPixmap{":/images/images/items/"+ type}.scaledToWidth(size*SCALE));
}


// Getters
QString ResourceView::getType() const {
    return m_type;
}

void ResourceView::setBuildingCardPlace(BuildingCardPlace *place) {
    m_buildingCard = place;
    m_civilCard = nullptr;
    setClickable();
}

void ResourceView::setCivilCardPlace(CivilisationCardPlace *place) {
    m_civilCard = place;
    m_buildingCard = nullptr;
    setClickable();
}


// Setters
void ResourceView::setClickable() {
    if (m_clickable) {
        setFlag(ItemIsSelectable);
    }
}

void ResourceView::unsetClickable() {
    setFlag(ItemIsSelectable, false);
}

void ResourceView::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    if (m_clickable) {
        if (m_buildingCard != nullptr) {
            if (event->button() == Qt::LeftButton) {
                if (m_type == "wood")
                    m_buildingCard->addTempResources(1, 0, 0, 0);
                else if (m_type == "brick")
                    m_buildingCard->addTempResources(0, 1, 0, 0);
                else if (m_type == "stone")
                    m_buildingCard->addTempResources(0, 0, 1, 0);
                else if (m_type == "gold")
                    m_buildingCard->addTempResources(0, 0, 0, 1);
            }
            else {
                if (m_type == "wood")
                    m_buildingCard->removeTempResources(1, 0, 0, 0);
                else if (m_type == "brick")
                    m_buildingCard->removeTempResources(0, 1, 0, 0);
                else if (m_type == "stone")
                    m_buildingCard->removeTempResources(0, 0, 1, 0);
                else if (m_type == "gold")
                    m_buildingCard->removeTempResources(0, 0, 0, 1);
            }
        }
        else {
            if (event->button() == Qt::LeftButton) {
                if (m_type == "wood")
                    m_civilCard->addTempResources(1, 0, 0, 0);
                else if (m_type == "brick")
                    m_civilCard->addTempResources(0, 1, 0, 0);
                else if (m_type == "stone")
                    m_civilCard->addTempResources(0, 0, 1, 0);
                else if (m_type == "gold")
                    m_civilCard->addTempResources(0, 0, 0, 1);
            }
            else {
                if (m_type == "wood")
                    m_civilCard->removeTempResources(1, 0, 0, 0);
                else if (m_type == "brick")
                    m_civilCard->removeTempResources(0, 1, 0, 0);
                else if (m_type == "stone")
                    m_civilCard->removeTempResources(0, 0, 1, 0);
                else if (m_type == "gold")
                    m_civilCard->removeTempResources(0, 0, 0, 1);
            }
        }


    }

    qDebug() << "@ResourceView.cpp - Clicked";
}
