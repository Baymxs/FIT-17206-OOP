//
// Created by Bayramov Nidjat on 13.09.18.
//

#ifndef LAB_1_TRITSET_H
#define LAB_1_TRITSET_H

#define UINT_SIZE 4 * sizeof(uint)

#include <cstdint>
#include <memory.h>
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
        TritSet(TritSet const&);

        Trit      operator[](size_t) const;
        Reference operator[](size_t);

        TritSet&  operator=(TritSet const&);

        size_t size() const;

    private:
        uint *_array;
        size_t _real_size;
        size_t _allocated_size;
        size_t _array_size;

        void _changeTritSetSize(size_t new_size);
        void _setTrit(Trit, size_t);
        Trit _getTrit(size_t) const;
};

TritSet operator&(const TritSet &trit_set_1, const TritSet &trit_set_2);
TritSet operator|(const TritSet &trit_set_1, const TritSet &trit_set_2);
TritSet operator~(const TritSet &trit_set);

bool operator==(const TritSet &trit_set_1, const TritSet &trit_set_2);
bool operator!=(const TritSet &trit_set_1, const TritSet &trit_set_2);
#endif //LAB_1_TRITSET_H
