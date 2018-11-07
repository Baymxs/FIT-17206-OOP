//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_STACKCALCULATOR_H
#define LAB_2_STACKCALCULATOR_H

#include <stack>
#include <map>
#include <string>
#include "Context.h"

class StackCalculator {
    public:
        static std::string input_stream_name;

        StackCalculator(int argc, char* argv[]);

        void calculate();

    private:
        void _readDataFromFile(Context &context);
        void _readDataFromStdin(Context &context);
};

#endif //LAB_2_STACKCALCULATOR_H