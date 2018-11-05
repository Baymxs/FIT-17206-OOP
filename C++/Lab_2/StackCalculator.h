//
// Created by Bayramov Nidjat on 04.11.18.
//

#ifndef LAB_2_STACKCALCULATOR_H
#define LAB_2_STACKCALCULATOR_H

#include <stack>
#include <map>
#include <string>

class StackCalculator {
    public:
        static std::stack<double> stack;
        static std::map<std::string, std::string> define_map;
        static std::string input_stream_name;

        StackCalculator(int argc, char* argv[]);

        void calculate();

    private:
        void _readDataFromFile();
        void _readDataFromStdin();
};

#endif //LAB_2_STACKCALCULATOR_H