//
// Created by Bayramov Nidjat on 21.11.18.
//
#include "../WindowFactory.h"
#include "../WindowCreators/MenuCreator.h"

//Initialize the window before running main
//Anonymous namespace
namespace {
    //Global function
    bool initializeMenuWindow() {
        WindowFactory::getInstance().registerWindows("Menu", new MenuCreator());
        return true;
    }
    //Calling the global function
    auto state = initializeMenuWindow();
}

void MenuWindow::execute() {

}
