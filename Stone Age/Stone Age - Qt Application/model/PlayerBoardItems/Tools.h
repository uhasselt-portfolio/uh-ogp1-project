#ifndef TOOLS_H
#define TOOLS_H

#include <QVector>

#include "Tool.h"
class Tool;
class Game;

class Tools {
    public:
        // Constructor
        Tools(QVector<Tool*> tools = {}, Game* game=nullptr);

        // Getters
        QVector<Tool*> getTools() const;
        int getAmountOfTools() const;

        // Setters
        void upgradeNextTool();
        void resetTools();
        void setTools(QVector<Tool*> tools);
        void addFiniteTool(int amountOfUse);

        // MVC
        void useTool(int level);

    private:
        QVector<Tool*> m_tools;
        Game* m_game;
};

#endif // TOOLS_H
