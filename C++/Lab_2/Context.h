//
// Created by Bayramov Nidjat on 07.11.18.
//

#ifndef LAB_2_CONTEXT_H
#define LAB_2_CONTEXT_H

#include <stack>
#include <map>
#include <vector>

class Context {
    private:
        std::stack<double> stack;
        std::map<std::string, std::string> define_map;

    public:
        Context(std::ostream &ostream)
            : output_stream(ostream) {}

        std::string getMapValueByKey(std::string key);
        void setMapValueByKey(std::string key, std::string value);
        std::map<std::string, std::string>::iterator findMapValueByKey(std::string key);
        std::map<std::string, std::string>::iterator getEndIterator();

        size_t stackSize();
        bool stackEmptiness();
        double stackTop();
        void stackPop();
        void stackPush(double value);

        std::ostream &output_stream;
};


#endif //LAB_2_CONTEXT_H
