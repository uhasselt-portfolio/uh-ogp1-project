#ifndef CARDINVENTORYVIEW_H
#define CARDINVENTORYVIEW_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>

class CardView;

class CardInventoryView : public QObject, public QGraphicsRectItem {
    Q_OBJECT
    public:
        // Constructor
        CardInventoryView(int x, int y, int w, int h, QGraphicsScene* scene);

        // Visuals
        void displayCards(QVector<QString> paths, QString pathPrefix);
        void removeCards();

    public slots:
        void r_updateBuildingInventory(QVector<QString> paths);
        void r_updateCivilisationInventory(QVector<QString> paths);

    private:
        int m_cardX;
        int m_cardY;
        int m_rows;
        int m_cols;

        QVector<CardView*> m_cards;
};

#endif // CARDINVENTORYVIEW_H
