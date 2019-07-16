#ifndef BUILDINGCARD_H
#define BUILDINGCARD_H

#include <QVector>
#include <QString>

class Resource;
class Game;

class BuildingCard {
    public:
        // Constructors
        BuildingCard(int returnPoints, QString imagePath, Game* game);

        // Getters
        QString getImagePath() const;
        virtual bool checkValidResources() const = 0;
        virtual int getReturnPoints() const = 0;
        virtual int getType() const = 0;
        QVector<Resource *> getGivenResources() const;

        // Utils
        void setGivenResources(QVector<Resource*> resources);
        static QVector<int> convertResources(QVector<Resource*> resources);
        static QVector<Resource*> convertResourcesBack(QVector<int> resources);

    protected:
        Game* m_game;
        QVector<Resource*> m_givenResources;
        int m_returnPoints;

    private:
        QString m_imagePath;

};


#endif // BUILDINGCARD_H
