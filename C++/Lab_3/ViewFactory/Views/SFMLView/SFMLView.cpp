//
// Created by Bayramov Nidjat on 28.11.18.
//

#include "SFMLView.h"
#include "../../ViewFactory.h"
#include "../../ViewCreators/SFMLCreator.h"
#include "WindowFactory/WindowFactory.h"

//Initialize the view before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeSFMLView() {
        ViewFactory::getInstance().registerView("SFML", new SFMLCreator());
        return true;
    }
    //Calling the global function
    auto state = initializeSFMLView();
}

void SFMLView::render(BattleShipModel *battleShipModel) {
    window = WindowFactory::getInstance().getWindow(battleShipModel->getGameStage());
    window->setMainWindow(&main_window);
    window->render(battleShipModel);
}
