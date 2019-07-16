#ifndef GAMEBUTTONVIEW_H
#define GAMEBUTTONVIEW_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QString>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>

class GameButtonView : public QObject, public QGraphicsRectItem {
    Q_OBJECT

    public:
        // Constructor
        GameButtonView(int top, int size, QString text, QGraphicsItem *parent = nullptr);
        GameButtonView(int top, int right, int size, QString text, QGraphicsItem *parent = nullptr);

        // Setters
        void setBtnText(QString text, QGraphicsItem* parent);
        void moveDown(int amount, QGraphicsItem* parent);

        // Events
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    signals:
        void s_buttonClicked(QString text);

    private:
        QGraphicsTextItem *m_buttonText;
        int m_top;
        int m_size;
};

#endif // GAMEBUTTONVIEW_H
