//
// Created by Bayramov Nidjat on 07.11.18.
//

#ifndef LAB_2_NOTNUMBEREXCEPTION_H
#define LAB_2_NOTNUMBEREXCEPTION_H

#include <stdexcept>

class NotNumberException : public std::runtime_error {
    public:
        explicit NotNumberException(char const* const message) noexcept
                : runtime_error(message) {}
};

#endif //LAB_2_NOTNUMBEREXCEPTION_H
