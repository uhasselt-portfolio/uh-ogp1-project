#ifndef ANNOUNCEVIEW_H
#define ANNOUNCEVIEW_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QString>
#include <QObject>
#include <QFont>

class GameButtonView;
class BuildingCardPlace;
class CivilisationCardPlace;
class Tool;
class Game;

class AnnounceView : public QObject, public QGraphicsRectItem {
    Q_OBJECT

    public:
        // Constructor
        AnnounceView(int x, int y, int w, int h, QGraphicsScene *scene = nullptr, Game* game=nullptr);
        
        // Getters
        GameButtonView* getNextBtn() const;
        GameButtonView* getPayBtn() const;

        // Utils
        void announceBig(QString text);
        void announceSmall(QString text);

        void announceRecources(QVector<int> dice, QString calc, QString resType, QVector<Tool*> tools);
        void announcePayResources(BuildingCardPlace* place, QVector<int> resources, bool changeable = true);
        void clean();



    public slots:
        void r_announceSmall(QString text);
        void r_announceResources(QVector<int> dice, QString calc, QString resType, QVector<Tool*> tools);
        void r_announcePayResources(BuildingCardPlace* bPlace, CivilisationCardPlace* cPlace, QVector<int> resources, bool changeable = true);

        void r_payResources();
        void r_claimRescources();

    private:
        QGraphicsTextItem* m_announceText;
        GameButtonView* m_nextBtn;
        GameButtonView* m_claimBtn;
        GameButtonView* m_payBtn;

        QFont m_smallFont;
        QFont m_bigFont;
        Game* m_game;

};


#endif // ANNOUNCEVIEW_H
