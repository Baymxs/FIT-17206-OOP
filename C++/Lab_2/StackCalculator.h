//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_STACKCALCULATOR_H
#define LAB_2_STACKCALCULATOR_H

#include <stack>
#include <map>
#include <string>
#include <iostream>
#include "Context.h"

class StackCalculator {
    public:
        StackCalculator(std::istream &istream, std::ostream &ostream);
        void calculate();

    private:
        std::istream &input_stream;
        std::ostream &output_stream;
        void _readData(Context &context);
};

#endif //LAB_2_STACKCALCULATOR_H