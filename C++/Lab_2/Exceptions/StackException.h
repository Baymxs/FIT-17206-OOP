//
// Created by Bayramov Nidjat on 06.11.18.
//

#ifndef LAB_2_STACKEXCEPTION_H
#define LAB_2_STACKEXCEPTION_H

#include <exception>
#include <stdexcept>
#include <string>

class StackException : public std::runtime_error {
    public:
        explicit StackException(char const* const message) noexcept
            : runtime_error(message) {}
};

#endif //LAB_2_STACKEXCEPTION_H
