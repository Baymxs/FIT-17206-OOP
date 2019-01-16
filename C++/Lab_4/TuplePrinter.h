//
// Created by Bayramov Nidjat on 15.01.19.
//

#ifndef LAB_4_TUPLEPRINTER_H
#define LAB_4_TUPLEPRINTER_H

#include <cstdio>
#include <iostream>

template <class Tuple, std::size_t N>
class TuplePrinter {
    public:
        static void print(std::ostream &out, Tuple& t) {
            TuplePrinter<Tuple, N-1>::print(out, t);
            out << ", " << std::get<N-1>(t);
        }
};

template <class Tuple>
class TuplePrinter<Tuple, 1> {
    public:
        static void print(std::ostream &out, const Tuple& t) {
            out << std::get<0>(t);
        }
};

template <typename ...Args>
std::ostream &printTuple(std::ostream &out, const std::tuple<Args...> &t) {
    out << "(";
    TuplePrinter<decltype(t), sizeof...(Args)>::print(out, t);
    out << ")\n";

    return out;
}

template <typename ...Args>
std::ostream &operator<<(std::ostream &out, const std::tuple<Args...> &tuple) {
    return printTuple(out, tuple);
}

#endif //LAB_4_TUPLEPRINTER_H
