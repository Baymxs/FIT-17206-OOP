//
// Created by Bayramov Nidjat on 07.11.18.
//

#ifndef LAB_2_CONTEXT_H
#define LAB_2_CONTEXT_H

#include <stack>
#include <map>

class Context {
    public:
        std::stack<double> stack;
        std::map<std::string, std::string> define_map;
};


#endif //LAB_2_CONTEXT_H
