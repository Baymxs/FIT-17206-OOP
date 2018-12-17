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

void SFMLView::render() {
    if (getBattleShipModel()->getGameStage() == "Exit") {
        getMainWindow()->close();
    }
    if (getBattleShipModel()->getBattleShipMenuModel().getMusicModeChanged()) {
        if (getBattleShipModel()->getBattleShipMenuModel().getVolumeSelection() == 2) {
            sound.pause();
        } else if (getBattleShipModel()->getBattleShipMenuModel().getVolumeSelection() == 1) {
            sound.play();
        }
        getBattleShipModel()->getBattleShipMenuModel().setMusicModeChanged(false);
    }

    if (getBattleShipModel()->getWindowChanges()) {
        window = WindowFactory::getInstance().getWindow(this->getBattleShipModel());
        getBattleShipModel()->setWindowChanges(false);
    }

    window->setMainWindow(&main_window);
    window->render();
}
