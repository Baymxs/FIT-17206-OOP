#include <utility>

//
// Created by Bayramov Nidjat on 07.11.18.
//

#include "Context.h"
#include <string>

std::string Context::getMapValueByKey(std::string key) {
    return define_map[key];
}

void Context::setMapValueByKey(std::string key, std::string value) {
    define_map[key] = std::move(value);
}

std::map<std::string, std::string>::iterator Context::findMapValueByKey(std::string key) {
    return define_map.find(key);
}

bool Context::stackEmptiness() {
    return stack.empty();
}

size_t Context::stackSize() {
    return stack.size();
}

double Context::stackTop() {
    return stack.top();
}

void Context::stackPop() {
    stack.pop();
}

void Context::stackPush(double value) {
    stack.push(value);
}

std::map<std::string, std::string>::iterator Context::getEndIterator() {
    return define_map.end();
}
