//
// Created by Bayramov Nidjat on 07.11.18.
//

#ifndef LAB_2_WRONGCOMMANDNAMEEXCEPTION_H
#define LAB_2_WRONGCOMMANDNAMEEXCEPTION_H

#include "stdexcept"

class WrongCommandNameException : public std::runtime_error {
public:
    explicit WrongCommandNameException(char const* const message) noexcept
            : runtime_error(message) {}
};

#endif //LAB_2_WRONGCOMMANDNAMEEXCEPTION_H
