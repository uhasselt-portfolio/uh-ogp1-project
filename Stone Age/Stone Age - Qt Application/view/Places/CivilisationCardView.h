#ifndef CIVILVIEW_H
#define CIVILVIEW_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QString>

#include "PlaceView.h"

class Game;
class Place;
class CivilisationCardPlace;
class CardView;

class CivilisationCardView : public PlaceView {
    public:
        // Constructor
        CivilisationCardView(int x, int y, int w, int h, CivilisationCardPlace* civilisationCardPlace, QGraphicsItem *parent = nullptr, Game* game = nullptr, Place* place = nullptr);

        CardView* getCard() const;

        // Events
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    public slots:
        void r_removeCivilisationCardView();
        void r_addCivilisationCardView(QString imageName);

    private:
        CivilisationCardPlace* m_civilisationCardPlace;
};

#endif // CIVILVIEW_H
