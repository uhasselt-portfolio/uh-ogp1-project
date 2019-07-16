#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QJsonObject>
#include <QJsonArray>

class Game;
class Players;
class BuildingCard;
class CivilisationCard;

class FileHandler {
    public:
        // Constructor
        FileHandler(Game* game);

        // Export
        void exportJson(QString path = "saved/data.json");
        void saveGame(QString path = "saved/data.json");

        QJsonArray playersToJson();
        QJsonObject gameRoundsToJson();
        QJsonObject gameStateToJson();
        QJsonArray buildingCardsToJson(QVector<BuildingCard*> buildingCardsData);
        QJsonArray civilCardsToJson(QVector<CivilisationCard*> civilCardsData);

        // Import
        void importJson(QString path = "saved/data.json");
        void loadGame(QString path = "saved/data.json");

        void loadPlayers(QJsonArray players);
        void loadGameRounds(QJsonValue gameRounds);
        void loadGameState(QJsonValue gameState);

        QVector<BuildingCard*> jsonToBuilingCards(QJsonArray buildingCards);
        QVector<CivilisationCard*> jsonToCivilCards(QJsonArray civilCards);

        // Building cards
        QVector<BuildingCard*> importBuildingCards();
        QVector<CivilisationCard*> importCivilisationCards();

    private:
        Game* m_game;
};



#endif // FILEHANDLER_H
