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
    private:
        uint *_array;
        size_t _real_size;
        size_t _allocated_size;
        size_t _array_size;

    private:
        void _changeTritSetSize(size_t new_size);

    public:
        TritSet(size_t size, Trit value);
        Trit operator[](size_t index) const;
        TritSet& operator=(TritSet const& tritSet);
        void setTrit(Trit value, size_t index);
        size_t getRealSize() const;
        Trit getTrit(size_t index) const;

    class Reference {
        size_t position;
    };
};

TritSet operator&(const TritSet &trit_set_1, const TritSet &trit_set_2);
TritSet operator|(const TritSet &trit_set_1, const TritSet &trit_set_2);
TritSet operator~(const TritSet &trit_set);

bool operator==(const TritSet &trit_set_1, const TritSet &trit_set_2);
bool operator!=(const TritSet &trit_set_1, const TritSet &trit_set_2);
#endif //LAB_1_TRITSET_H
