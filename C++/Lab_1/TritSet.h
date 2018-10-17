//
// Created by Bayramov Nidjat on 13.09.18.
//

#ifndef LAB_1_TRITSET_H
#define LAB_1_TRITSET_H

#define UINT_SIZE 4 * sizeof(uint)

#include <cstdint>
#include <memory.h>
#include <iostream>
#include <unordered_map>
#include "Trit.h"

typedef uint32_t uint;

class TritSet {
    public:
        class Reference {
            friend class TritSet;

            public:
                TritSet& operator=(Trit);
                explicit operator Trit() const;

            private:
                Reference(TritSet&, size_t);
                TritSet& _tritSet;
                size_t _position;

        };

        explicit TritSet(size_t = 0, Trit = UNKNOWN);

        TritSet(const TritSet&);
        TritSet&  operator=(const TritSet&);

        TritSet(TritSet &&);
        TritSet& operator=(TritSet&&);
        ~TritSet();


        Trit      operator[](size_t) const;
        Reference operator[](size_t);


        size_t size() const;

        size_t cardinality(Trit value) const;
        std::unordered_map<Trit, size_t, std::hash<size_t>> cardinality() const;

        void trim(size_t);
        size_t capacity() const;
        void shrink();
    private:
        uint *_array;

        size_t _allocated_size;
        size_t _array_size;
        size_t _max_size;
        size_t _logical_size;

        size_t _true_count = 0;
        size_t _false_count = 0;
        size_t _unknown_count = 0;

        void _changeTritSetSize(size_t new_size);
        void _setTrit(Trit, size_t);
        void _changeCountsOfTrits(size_t new_value, Trit old_value);
        void _setStartCounts(Trit, size_t);
        Trit _getTrit(size_t) const;
        size_t _search_last_index() const;
};

TritSet operator&(const TritSet &trit_set_1, const TritSet &trit_set_2);
TritSet operator|(const TritSet &trit_set_1, const TritSet &trit_set_2);
TritSet operator~(const TritSet &trit_set);

bool operator==(const TritSet &trit_set_1, const TritSet &trit_set_2);
bool operator!=(const TritSet &trit_set_1, const TritSet &trit_set_2);
#endif //LAB_1_TRITSET_H
