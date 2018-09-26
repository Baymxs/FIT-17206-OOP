//
// Created by Bayramov Nidjat on 13.09.18.
//

#include "TritSet.h"

//Operator '&' overloading for TritSet
TritSet operator&(const TritSet &trit_set_1, const TritSet &trit_set_2) {
    size_t new_size = trit_set_1.getRealSize() > trit_set_2.getRealSize() ? trit_set_1.getRealSize() : trit_set_2.getRealSize();
    TritSet new_trit_set(new_size);

    for (size_t i = 0; i < new_size; i++)
         new_trit_set[i] = trit_set_1[i] & trit_set_2[i];

    return new_trit_set;
}

//Operator '|' overloading for TritSet
TritSet operator|(const TritSet &trit_set_1, const TritSet &trit_set_2) {
    size_t new_size = trit_set_1.getRealSize() > trit_set_2.getRealSize() ? trit_set_1.getRealSize() : trit_set_2.getRealSize();

    TritSet new_trit_set(new_size);

    for (size_t i = 0; i < new_size; i++)
        new_trit_set[i] = trit_set_1[i] | trit_set_2[i];

    return new_trit_set;
}

//Operator '~' overloading for TritSet
TritSet operator~(const TritSet &trit_set) {
    TritSet new_trit_set(trit_set.getRealSize());

    for (size_t i = 0; i < trit_set.getRealSize(); i++)
            new_trit_set[i] = !trit_set[i];
}

//Operator '==' overloading for TritSet
bool operator==(const TritSet &trit_set_1, const TritSet &trit_set_2) {
    if (trit_set_1.getRealSize() != trit_set_2.getRealSize()) return false;

    for (size_t i = 0; i < trit_set_1.getRealSize(); i++)
        if (trit_set_1[i] != trit_set_2[i]) return false;

    return true;
}

//Operator '!=' overloading for TritSet
bool operator!=(const TritSet trit_set_1, const TritSet trit_set_2) {
    return !(trit_set_1 == trit_set_2);
}

//Operator '[]' overloading for TritSet
Trit TritSet::operator[](size_t index) const {
    return getTrit(index);
}

//Constructor with size and trit value
TritSet::TritSet(size_t size, Trit value) {
    _real_size = _array_size = size;
    _allocated_size = ((size / UINT_SIZE) == 0 || size == UINT_SIZE) ? 1 : ((size / UINT_SIZE) + 1);
    _array = new uint[_allocated_size];

    uint mask = 0;

    //Fill 32 bits of uint with value using mask
    for (size_t i = 0 ; i < UINT_SIZE; i++)
        mask |= value << i * 2;

    //Fill elements of uint array with mask
    for (uint *i = _array; i != _array + _allocated_size + 1 ; i++)
        *i = mask;
}

size_t TritSet::getRealSize() const {
    return this->_real_size;
}

//Get Trit from the TritSet by index
Trit TritSet::getTrit(size_t index) const {
    if (index >= _real_size) return UNKNOWN;
    return Trit((_array[index / UINT_SIZE] >> (index % UINT_SIZE * 2)) & 0x3);
}

//Set the value of the trit at a certain position
void TritSet::setTrit(Trit value, size_t index) {
    //[0..]
    size_t uint_position = index / UINT_SIZE;

    if (index >= _real_size) {
        if (value == UNKNOWN) return;

        _changeTritSetSize(uint_position + 1);
        _real_size = index + 1;
    }

    //[0..15]
    size_t trit_position = index % UINT_SIZE;

    //First, we use a mask that will be & with the original uint to nullify the necessary bits of the trit
    //And || the result with
     _array[uint_position] = static_cast<uint>(((~(3 << (trit_position * 2))) & _array[uint_position]) || (value << (trit_position * 2)));
}

void TritSet::_changeTritSetSize(size_t new_size) {
    uint *new_array = new uint[new_size];

    if (new_size > _array_size) {
        memmove(new_array, _array, _array_size * sizeof(uint));
        memset(&new_array[_array_size], 0, (new_size - _array_size) * sizeof(uint));

    } else memmove(new_array, _array, new_size * sizeof(uint));

    _array_size = new_size;

    delete []_array;
    _array = new_array;
}



