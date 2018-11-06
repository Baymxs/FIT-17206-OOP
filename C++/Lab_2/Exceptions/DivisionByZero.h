//
// Created by Bayramov Nidjat on 07.11.18.
//

#ifndef LAB_2_DIVISIONBYZERO_H
#define LAB_2_DIVISIONBYZERO_H

#include "stdexcept"

class DivisionByZeroException : public std::runtime_error {
    public:
        explicit DivisionByZeroException(char const* const message) noexcept
                : runtime_error(message) {}
};

#endif //LAB_2_DIVISIONBYZERO_H
