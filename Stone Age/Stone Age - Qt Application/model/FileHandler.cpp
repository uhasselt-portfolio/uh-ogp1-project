#include "FileHandler.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QFile>

#include <QDebug>

#include "config.h"
#include "Team.h"

#include "Game.h"
#include "Players.h"
#include "Player.h"
#include "PlayerBoard.h"
#include "GameBoard.h"
#include "CardStack.h"
#include "BuildingCardStack.h"

#include "PlayerBoardItems/Food.h"
#include "PlayerBoardItems/FoodTracker.h"
#include "PlayerBoardItems/Resource.h"
#include "PlayerBoardItems/ScoreTracker.h"
#include "PlayerBoardItems/Tool.h"
#include "PlayerBoardItems/Tools.h"
#include "PlayerBoardItems/Worker.h"
#include "PlayerBoardItems/Workers.h"
#include "GameRoundManager.h"

#include "Cards/BuildingCard.h"
#include "Cards/SpecificResourceBuildingCard.h"
#include "Cards/SelectedResourceBuildingCard.h"
#include "Cards/RangedResourceBuildingCard.h"
#include "Cards/CivilisationCard.h"
#include "Cards/CivilisationCardHeader.h"
#include "Cards/CivilisationCardFooter.h"
#include "BuildingCardStack.h"


// Constructor
FileHandler::FileHandler(Game* game) : m_game{game} {}

// Exporting
void FileHandler::exportJson(QString path) {
    QJsonObject gameJson{};

    QJsonArray players{playersToJson()};
    QJsonObject gameRounds{gameRoundsToJson()};
    QJsonObject gameState{gameStateToJson()};

    gameJson.insert("Players", QJsonValue::fromVariant(players));
    gameJson.insert("GameRounds", QJsonValue::fromVariant(gameRounds));
    gameJson.insert("GameState", QJsonValue::fromVariant(gameState));
    QJsonDocument doc{gameJson};

    // Write to file
    QFile savedGame{path};
    savedGame.open(QFile::WriteOnly);
    savedGame.write(doc.toJson());
}
void FileHandler::saveGame(QString path) {
    if (m_game == nullptr) {
        qDebug() << "@FileHandler.cpp - Please init m_game (rn: nullptr)";
        return;
    }

    exportJson(path);
}

// Parsing
QJsonArray FileHandler::playersToJson() {
    Players* playersData{m_game->getPlayers()};
    QJsonArray players{};

    for(int i{0}, l{playersData->getSize()}; i < l; ++i) {
        // Player
        Player* playerData{playersData->getPlayer(i)};
        QJsonObject player{};
        player.insert("Name", QJsonValue::fromVariant(playerData->getName()));
        player.insert("Team", QJsonValue::fromVariant(static_cast<int>(playerData->getTeam())));

        // PlayerBoard
        PlayerBoard* playerBoardData{playerData->getPlayerBoard()};
        QJsonObject playerBoard{};

        playerBoard.insert("FoodAmount", QJsonValue::fromVariant(playerBoardData->getFoodStock()->getFoodSupply()));
        playerBoard.insert("FarmerLevel", QJsonValue::fromVariant(playerBoardData->getFoodTracker()->getFoodLevel()));
        playerBoard.insert("Score", QJsonValue::fromVariant(playerBoardData->getScoreTracker()->getScore()));

        // Resources
        QVector<Resource*> resourceStockData{playerBoardData->getResourceStock()};
        playerBoard.insert("Wood", QJsonValue::fromVariant(resourceStockData.at(WOOD_RESOURCE)->getCurrentAmount()));
        playerBoard.insert("Brick", QJsonValue::fromVariant(resourceStockData.at(BRICK_RESOURCE)->getCurrentAmount()));
        playerBoard.insert("Stone", QJsonValue::fromVariant(resourceStockData.at(STONE_RESOURCE)->getCurrentAmount()));
        playerBoard.insert("Gold", QJsonValue::fromVariant(resourceStockData.at(GOLD_RESOURCE)->getCurrentAmount()));

        // Tools
        QVector<Tool*> toolsData{playerBoardData->getTools()->getTools()};
        QJsonArray tools{};
        foreach(Tool* toolData, toolsData) {
            QJsonObject tool{};
            tool.insert("Level", QJsonValue::fromVariant(toolData->getLevel()));
            tool.insert("MaxLevel", QJsonValue::fromVariant(toolData->getMaximumLevel()));
            tool.insert("UseableTimes", QJsonValue::fromVariant(toolData->getUseableTimes()));
            tools.append(tool);
        }
        playerBoard.insert("Tools", QJsonValue::fromVariant(tools));

        // Building Cards
        QVector<BuildingCard*> buildingCardsData{playerBoardData->getCollectedBuildingCards()};
        playerBoard.insert("BuildingCards", buildingCardsToJson(buildingCardsData));

        // Civil Cards
        QVector<CivilisationCard*> civilCardsData{playerBoardData->getCollectedCivilisationCards()};
        playerBoard.insert("CivilCards", civilCardsToJson(civilCardsData));

        // Worker
        Workers* workersData{playerBoardData->getWorkers()};
        playerBoard.insert("WorkerAmount", QJsonValue::fromVariant(workersData->getWorkersCapacity()));
        player.insert("PlayerBoard", QJsonValue::fromVariant(playerBoard));
        players.append(player);
    }

    return players;
}
QJsonObject FileHandler::gameRoundsToJson() {
    GameRoundManager* gameRoundData{m_game->getGameRoundManager()};
    QJsonObject gameRounds{};
    gameRounds.insert("Round", QJsonValue::fromVariant(gameRoundData->getRound()));
    gameRounds.insert("Phase", QJsonValue::fromVariant(gameRoundData->getPhase()));
    gameRounds.insert("FirstPlayerIndex", QJsonValue::fromVariant(gameRoundData->getFirstPlayerIndex()));

    return gameRounds;
}
QJsonObject FileHandler::gameStateToJson() {
    QJsonObject gameState{};
    CardStack* cardStackData{m_game->getGameBoard()->getCardStack()};

    // Building Cards
    QJsonArray buildingCardStacks{};
    foreach(QVector<BuildingCard*> stack, cardStackData->getBuildingCardStack()->getBuildCardStacks()) {
        QJsonArray buildingCardStack{buildingCardsToJson(stack)};
        buildingCardStacks.append(buildingCardStack);
    }

    // Building card indexes
    QJsonArray indexes{};
    foreach(int indexData, cardStackData->getBuildingCardStack()->getBuildingStackIndexes()) {
        indexes.append(indexData);
    }

    gameState.insert("BuildingCardStack", buildingCardStacks);
    gameState.insert("CivilCardStack", civilCardsToJson(cardStackData->getCivilCardStack()));
    gameState.insert("CivilCardIndex", QJsonValue::fromVariant(cardStackData->getCivilCardIndex()));
    gameState.insert("BuildingCardIndexes", indexes);

    return gameState;
}
QJsonArray FileHandler::buildingCardsToJson(QVector<BuildingCard *> buildingCardsData) {
    // Building Cards
    QJsonArray buildingCards{};

    foreach(BuildingCard* buildingCardData, buildingCardsData) {
        QJsonObject buildingCard{};
        int cardType{buildingCardData->getType()};

        buildingCard.insert("Type", QJsonValue::fromVariant(cardType));
        buildingCard.insert("ImagePath", QJsonValue::fromVariant(buildingCardData->getImagePath()));

        if (cardType == 0) {
            SpecificResourceBuildingCard* buildingCardDataS{reinterpret_cast<SpecificResourceBuildingCard*>(buildingCardData)};

            // Resource array
            QVector<Resource*> requiredResourcesData{buildingCardDataS->getRequiredResources()};
            QJsonArray requiredResources{};
            foreach(Resource* resourceData, requiredResourcesData) {
                QJsonObject resource{};
                resource.insert("Type", QJsonValue::fromVariant(static_cast<int>(resourceData->getType())));
                resource.insert("Amount", QJsonValue::fromVariant(resourceData->getCurrentAmount()));
                requiredResources.append(resource);
            }
            buildingCard.insert("Resources", requiredResources);
            buildingCard.insert("ReturnPoints", QJsonValue::fromVariant(buildingCardDataS->getReturnPoints()));

        }
        else if (cardType == 1) {
            RangedResourceBuildingCard* buildingCardDataR{reinterpret_cast<RangedResourceBuildingCard*>(buildingCardData)};
            buildingCard.insert("Min", QJsonValue::fromVariant(buildingCardDataR->getMinimumResources()));
            buildingCard.insert("Max", QJsonValue::fromVariant(buildingCardDataR->getMaximumResources()));

        }
        else if (cardType == 2) {
            SelectedResourceBuildingCard* buildingCardDataS{reinterpret_cast<SelectedResourceBuildingCard*>(buildingCardData)};
            buildingCard.insert("Amount", QJsonValue::fromVariant(buildingCardDataS->getNumberOfKinds()));
            buildingCard.insert("Total", QJsonValue::fromVariant(buildingCardDataS->getTotalAmount()));
        }

        buildingCards.append(buildingCard);
    }

    return buildingCards;
}
QJsonArray FileHandler::civilCardsToJson(QVector<CivilisationCard *> civilCardsData) {
    QJsonArray civilCards{};

    foreach(CivilisationCard* civilCardData, civilCardsData) {
        QJsonObject civilCard{};
        civilCard.insert("ImagePath", QJsonValue::fromVariant(civilCardData->getImagePath()));

        CivilisationCardHeader* headerdata{civilCardData->getCardHeader()};
        CivilisationCardFooter* footerData{civilCardData->getCardFooter()};
        QJsonObject header{};
        QJsonObject footer{};

        header.insert("Type", QJsonValue::fromVariant(static_cast<int>(headerdata->getType())));
        header.insert("Amount", QJsonValue::fromVariant(headerdata->getAmount()));

        footer.insert("Type", QJsonValue::fromVariant(static_cast<int>(footerData->getCardType())));
        footer.insert("BackgroundType", QJsonValue::fromVariant(static_cast<int>(footerData->getBackgroundType())));
        footer.insert("Amount", QJsonValue::fromVariant(footerData->getAmountOfEntitiesOnCard()));

        civilCard.insert("Header", header);
        civilCard.insert("Footer", footer);

        civilCards.append(civilCard);
    }

    return civilCards;
}



// Importing
void FileHandler::importJson(QString path) {
    // Open file for reading
    QFile savedGame{path};
    savedGame.open(QIODevice::ReadOnly);
    QString savedGameJson{savedGame.readAll()};
    savedGame.close();

    // Go to json document
    QJsonDocument jsonDoc{QJsonDocument::fromJson(savedGameJson.toUtf8())};
    QJsonObject jsonObj{jsonDoc.object()};

    // Game Rounds
    QJsonValue gameRounds{jsonObj["GameRounds"]};
    loadGameRounds(gameRounds);

    // Players
    QJsonArray players{jsonObj["Players"].toArray()};
    loadPlayers(players);

    // GameState
    QJsonValue gameState{jsonObj["GameState"]};
    loadGameState(gameState);
}
void FileHandler::loadGame(QString path) {
    importJson(path);
}
void FileHandler::loadPlayers(QJsonArray players) {
    int counter{0};

    foreach(QJsonValue player, players) {
        // Player
        Player* currentPlayer{m_game->getPlayers()->getPlayer(counter)};
        currentPlayer->setName(QString {player["Name"].toString()});
        currentPlayer->setTeam(Team {Team(player["Team"].toInt())});

        // PlayerBoard
        PlayerBoard* currentPlayerBoard{currentPlayer->getPlayerBoard()};
        QJsonValue playerBoard{player["PlayerBoard"]};
        currentPlayerBoard->getFoodStock()->setFoodSupply(playerBoard["FoodAmount"].toInt());
        currentPlayerBoard->getFoodTracker()->setFoodLevel(playerBoard["FarmerLevel"].toInt());
        currentPlayerBoard->getScoreTracker()->setScore(playerBoard["Score"].toInt());

        // Resources
        currentPlayerBoard->getResourceStock().at(WOOD_RESOURCE)->setAmount(playerBoard["Wood"].toInt());
        currentPlayerBoard->getResourceStock().at(BRICK_RESOURCE)->setAmount(playerBoard["Brick"].toInt());
        currentPlayerBoard->getResourceStock().at(STONE_RESOURCE)->setAmount(playerBoard["Stone"].toInt());
        currentPlayerBoard->getResourceStock().at(GOLD_RESOURCE)->setAmount(playerBoard["Gold"].toInt());

        // Tools
        Tools* currentTools{currentPlayerBoard->getTools()};
        QJsonArray tools{playerBoard["Tools"].toArray()};
        QVector<Tool*> newTools{};

        foreach (QJsonValue tool, tools) {
            Tool* newTool{new Tool{tool["Level"].toInt(), tool["MaxLevel"].toInt(), tool["UseableTimes"].toInt()}};
            newTools.append(newTool);
        }
        currentTools->setTools(newTools);

        // Building Cards
        QJsonArray buildingCards{playerBoard["BuildingCards"].toArray()};
        currentPlayerBoard->setCollectedBuildingCards(jsonToBuilingCards(buildingCards));

        // Civil Cards
        QJsonArray civilCards{playerBoard["CivilCards"].toArray()};
        currentPlayerBoard->setCollectedCivilisationCards(jsonToCivilCards(civilCards));

        // Workers
        Workers* currentWorkers{currentPlayerBoard->getWorkers()};
        int currentWorkerAmount{currentWorkers->getWorkersCapacity()};
        int currentWorkersAmountJson{playerBoard["WorkerAmount"].toInt()};

        for (int i{0}, l{currentWorkersAmountJson - currentWorkerAmount}; i < l; ++i) {
            currentWorkers->increaseWorkersCapacity();
        }

        ++counter;
    }
}
void FileHandler::loadGameRounds(QJsonValue gameRounds) {
    m_game->getGameRoundManager()->setRound(gameRounds["Round"].toInt());
    m_game->getGameRoundManager()->setPhase(gameRounds["Phase"].toInt());
    m_game->getGameRoundManager()->setPhase(1);

    m_game->getGameRoundManager()->setFirstPlayerIndex(gameRounds["FirstPlayerIndex"].toInt());
}
void FileHandler::loadGameState(QJsonValue gameState) {
    CardStack* cardStackData{m_game->getGameBoard()->getCardStack()};

    // Building Card Stacks
    QVector<QVector<BuildingCard*>> cards;
    foreach(QJsonValue cardStack, gameState["BuildingCardStack"].toArray()) {
        cards.append(jsonToBuilingCards(cardStack.toArray()));
    }
    cardStackData->getBuildingCardStack()->setBuildingCardStacks(cards);

    // Civil Cards
    cardStackData->setCivilCards(jsonToCivilCards(gameState["CivilCardStack"].toArray()));

    // Civil Card Index
    cardStackData->setCivilCardIndex(gameState["CivilCardIndex"].toInt());

    // Building cards index
    QVector<int> indexes{};
    foreach(QJsonValue index, gameState["BuildingCardIndexes"].toArray()) {
        indexes.append(index.toInt());
    }
    cardStackData->getBuildingCardStack()->setBuildingStackIndexes(indexes);

}




QVector<BuildingCard*> FileHandler::importBuildingCards() {
    // Open file
    QFile savedJson{"saved/buildings.json"};
    savedJson.open(QIODevice::ReadOnly);
    QString buildingsJson{savedJson.readAll()};
    savedJson.close();

    // Go to json document
    QJsonDocument jsonDoc{QJsonDocument::fromJson(buildingsJson.toUtf8())};
    QJsonArray jsonArr{jsonDoc.array()};

    return jsonToBuilingCards(jsonArr);
}

QVector<CivilisationCard *> FileHandler::importCivilisationCards() {
    // Open file
    QFile savedJson{"saved/civilisations.json"};
    savedJson.open(QIODevice::ReadOnly);
    QString civilisationsJson{savedJson.readAll()};
    savedJson.close();

    // Go to json document
    QJsonDocument jsonDoc{QJsonDocument::fromJson(civilisationsJson.toUtf8())};
    QJsonArray jsonArr{jsonDoc.array()};

    return jsonToCivilCards(jsonArr);
}

QVector<BuildingCard *> FileHandler::jsonToBuilingCards(QJsonArray buildingCards) {
    QVector<BuildingCard*> buildingCardsData{};

    foreach(QJsonValue building, buildingCards) {
        int type{building["Type"].toInt()};
        QString imagePath{building["ImagePath"].toString()};

        if (type == 0) {
            int returnPoints{building["ReturnValue"].toInt()};
            QVector<Resource*> resourceObjs{};
            QJsonArray resources{building["Resources"].toArray()};
            foreach(QJsonValue resource, resources) {
                ResourceType type{ResourceType(resource["Type"].toInt())};
                resourceObjs.append(new Resource{type, resource["Amount"].toInt()});
            }

            buildingCardsData.append(new SpecificResourceBuildingCard{returnPoints, imagePath, resourceObjs, m_game});
        }
        else if(type == 1) {
            buildingCardsData.append(new RangedResourceBuildingCard{-1, imagePath, m_game, building["Min"].toInt(), building["Max"].toInt()});
        }
        else {
            buildingCardsData.append(new SelectedResourceBuildingCard{-1, imagePath, m_game, building["Amount"].toInt(), building["Total"].toInt()});
        }
    }

    return buildingCardsData;
}

QVector<CivilisationCard *> FileHandler::jsonToCivilCards(QJsonArray civilCards) {
    QVector<CivilisationCard*> civilCardsData{};

    foreach(QJsonValue civilisation, civilCards) {
        QString imagePath{civilisation["ImagePath"].toString()};
        QJsonObject footer{civilisation["Footer"].toObject()};
        QJsonObject header{civilisation["Header"].toObject()};

        int headerType{header["Type"].toInt()};
        int headerAmount{header["Amount"].toInt()};

        int footerBackgroundType{footer["BackgroundType"].toInt()};
        int footerCardType{footer["Type"].toInt()};
        int footerAmount{footer["Amount"].toInt()};

        CivilisationCardHeader* cch {new CivilisationCardHeader{static_cast<HeaderType>(headerType), headerAmount, m_game}};
        CivilisationCardFooter* ccf {new CivilisationCardFooter{static_cast<BackgroundType>(footerBackgroundType), static_cast<CardType>(footerCardType), footerAmount, m_game}};
        CivilisationCard* newCard{new CivilisationCard{imagePath, cch, ccf, m_game}};

        civilCardsData.append(newCard);
    }

    return civilCardsData;
}
