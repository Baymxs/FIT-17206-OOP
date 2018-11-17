//
// Created by Bayramov Nidjat on 07.11.18.
//

#ifndef LAB_3_CONSOLEVIEW_H
#define LAB_3_CONSOLEVIEW_H

#include <vector>
#include <map>

#include "../View.h"

class ConsoleView : public View {
public:
    void execute(std::vector<std::string>) override;
};

#endif //LAB_3_CONSOLEVIEW_H
