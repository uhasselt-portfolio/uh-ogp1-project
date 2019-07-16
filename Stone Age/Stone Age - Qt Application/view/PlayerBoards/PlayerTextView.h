#ifndef PLAYERTEXTVIEW_H
#define PLAYERTEXTVIEW_H

#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QString>

class PlayerTextView : public QGraphicsTextItem {
    public:
        // Constructor
        PlayerTextView(int x, int y, int padding, int fontSize, QString text, QGraphicsItem *parent = nullptr);
};

#endif // PLAYERTEXTVIEW_H
