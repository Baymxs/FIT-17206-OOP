//
// Created by Bayramov Nidjat on 06.11.18.
//

#ifndef LAB_2_ARGUMENTEXCEPTION_H
#define LAB_2_ARGUMENTEXCEPTION_H

#include "stdexcept"

class ArgumentException : public std::runtime_error {
    public:
        explicit ArgumentException(char const* const message) noexcept
            : runtime_error(message) {}
};

#endif //LAB_2_ARGUMENTEXCEPTION_H
