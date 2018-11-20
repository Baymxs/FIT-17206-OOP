//
// Created by Bayramov Nidjat on 07.11.18.
//

#ifndef LAB_3_CONSOLEVIEW_H
#define LAB_3_CONSOLEVIEW_H

#include <vector>
#include <map>

#include "../View.h"
#include "../../../BattleShipModel.h"
#include "../../WindowFactory/Window.h"

class ConsoleView : public View {
    private:
        BattleShipModel *battleShipModel = nullptr;
        Window *battleShipWindow = nullptr;
    public:
        void initializeModel(BattleShipModel &battleShipModel) override;
        void render() override;

};

#endif //LAB_3_CONSOLEVIEW_H
