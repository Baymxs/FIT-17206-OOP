//
// Created by Bayramov Nidjat on 13.09.18.
//

#include "TritSet.h"

//Operator '&' overloading for TritSet
TritSet operator&(const TritSet &trit_set_1, const TritSet &trit_set_2) {
    size_t new_size = trit_set_1.size() > trit_set_2.size() ? trit_set_1.size() : trit_set_2.size();
    TritSet new_trit_set(new_size);

    for (size_t i = 0; i < new_size; i++)
         new_trit_set[i] = trit_set_1[i] & trit_set_2[i];

    return new_trit_set;
}

//Operator '|' overloading for TritSet
TritSet operator|(const TritSet &trit_set_1, const TritSet &trit_set_2) {
    size_t new_size = trit_set_1.size() > trit_set_2.size() ? trit_set_1.size() : trit_set_2.size();

    TritSet new_trit_set(new_size);

    for (size_t i = 0; i < new_size; i++)
        new_trit_set[i] = trit_set_1[i] | trit_set_2[i];

    return new_trit_set;
}

//Operator '~' overloading for TritSet
TritSet operator~(const TritSet &trit_set) {
    TritSet new_trit_set(trit_set.size());

    for (size_t i = 0; i < trit_set.size(); i++)
            new_trit_set[i] = ~trit_set[i];
    return new_trit_set;
}

//Operator '==' overloading for TritSet
bool operator==(const TritSet &trit_set_1, const TritSet &trit_set_2) {
    if (trit_set_1.size() != trit_set_2.size()) return false;

    for (size_t i = 0; i < trit_set_1.size(); i++)
        if (trit_set_1[i] != trit_set_2[i]) return false;

    return true;
}

//Operator '!=' overloading for TritSet
bool operator!=(const TritSet &trit_set_1, const TritSet &trit_set_2) {
    return !(trit_set_1 == trit_set_2);
}

//Operator '[]' overloading for TritSet
Trit TritSet::operator[](size_t index) const {
    return _getTrit(index);
}

//Constructor with size and trit value
TritSet::TritSet(size_t size, Trit value) : _max_size(size), _logical_size(value == UNKNOWN ? 0 : size) {
    _setStartCounts(value, size);

    _array_size = _allocated_size = ((size / UINT_SIZE) == 0 || size == UINT_SIZE) ? 1 : ((size / UINT_SIZE) + 1);
    _array = new uint[_allocated_size];

    uint mask = 0;

    //Fill 32 bits of uint with value using mask
    for (size_t i = 0 ; i < UINT_SIZE; i++)
        mask |= value << i * 2;


    //Fill elements of uint array with mask
    for (uint *i = _array; i != _array + _allocated_size + 1 ; i++)
        *i = mask;

}

//Copy constructor
TritSet::TritSet(const TritSet &tritSet) :
        _allocated_size(tritSet._allocated_size),
        _array_size(tritSet._array_size),
        _max_size(tritSet._max_size),
        _logical_size(tritSet._logical_size),

        _true_count(tritSet._true_count),
        _false_count(tritSet._false_count),
        _unknown_count(tritSet._unknown_count),
        _array(new uint[tritSet._array_size])
{
    memmove(this->_array, tritSet._array, tritSet._array_size * sizeof(uint));
}

//Overload operator '=' in case, when we equate to one TritSet another TritSet
//Copy Assignment Operator
TritSet& TritSet::operator=(TritSet const& tritSet) {
    if (this == &tritSet)
        return *this;

    delete[] _array;

    _allocated_size = tritSet._allocated_size;
    _array_size = tritSet._array_size;
    _max_size = tritSet._max_size;
    _logical_size = tritSet._logical_size;

    _true_count = tritSet._true_count;
    _false_count = tritSet._false_count;
    _unknown_count = tritSet._unknown_count;

    _array = new uint[_array_size];
    memcpy(_array, tritSet._array, tritSet._array_size * sizeof(uint));

    return *this;
}

//Move constructor
TritSet::TritSet(TritSet &&tritSet) :
    _allocated_size(tritSet._allocated_size),
    _array_size(tritSet._array_size),
    _max_size(tritSet._max_size),
    _logical_size(tritSet._logical_size),

    _true_count(tritSet._true_count),
    _false_count(tritSet._false_count),
    _unknown_count(tritSet._unknown_count),

    _array(tritSet._array)
{
    tritSet._allocated_size = 0;
    tritSet._array_size = 0;
    tritSet._max_size = 0;
    tritSet._logical_size = 0;

    tritSet._true_count = 0;
    tritSet._false_count = 0;
    tritSet._unknown_count = 0;

    tritSet._array = nullptr;
}

//Overload operator '=' in case, when we equate to one TritSet another TritSet
//Move Assignment Operator
TritSet& TritSet::operator=(TritSet&& tritSet) {
    if (this == &tritSet)
        return *this;

    delete[] _array;

    _allocated_size = tritSet._allocated_size;
    _array_size = tritSet._array_size;
    _max_size = tritSet._max_size;
    _logical_size = tritSet._logical_size;

    _true_count = tritSet._true_count;
    _false_count = tritSet._false_count;
    _unknown_count = tritSet._unknown_count;

    _array = tritSet._array;

    tritSet._allocated_size = 0;
    tritSet._array_size = 0;
    tritSet._max_size = 0;
    tritSet._logical_size = 0;

    tritSet._true_count = 0;
    tritSet._false_count = 0;
    tritSet._unknown_count = 0;

    tritSet._array = nullptr;

    return *this;
}

//Destructor
TritSet::~TritSet() {
    delete[] _array;
}

size_t TritSet::size() const {
    return this->_logical_size;
}

//Get Trit from the TritSet by index
Trit TritSet::_getTrit(size_t index) const {
    if (index >= _max_size) return UNKNOWN;
    return Trit((_array[index / UINT_SIZE] >> (index % UINT_SIZE * 2)) & 0x3);
}

//Set the value of the trit at a certain position
void TritSet::_setTrit(Trit value, size_t index) {
    //[0..]
    size_t uint_position = index / UINT_SIZE;

    if (index >= _max_size) {
        if (value == UNKNOWN) return;

        _changeTritSetSize(uint_position + 1);
        _max_size = index + 1;
    }

    //[0..15]
    size_t trit_position = index % UINT_SIZE;

    size_t uint_value = _array[uint_position]>>(trit_position * 2) & 0x3;

    if (value != uint_value) {
        //Change trit counters
        _changeCountsOfTrits(uint_value, value);

        //First, we use a mask that will be & with the original uint to nullify the necessary bits of the trit
        //And || the result with
        size_t value_with_shift = ((uint) value << (trit_position * 2));

        //Here we directly change the trit value in tritSet by index
        _array[uint_position] = static_cast<uint>(((~(3 << (trit_position * 2))) & _array[uint_position]) |
                                                  value_with_shift);
    }

    if (index + 1 == _logical_size && value == UNKNOWN) {
        _logical_size = _search_last_index() + 1;
    } else {
        if (value != UNKNOWN && index + 1 > _logical_size) {
            _logical_size = index + 1;
        }
    }
}

//Change the TritSet size
void TritSet::_changeTritSetSize(size_t new_size) {
    uint *new_array = new uint[new_size];

    if (new_size > _array_size) {
        //Copy
        memmove(new_array, _array, _array_size * sizeof(uint));
        //Fill with values
        memset(&new_array[_array_size], 0, (new_size - _array_size) * sizeof(uint));

    } else memmove(new_array, _array, new_size * sizeof(uint));

    _array_size = new_size;

    delete []_array;
    _array = new_array;
}

//Overload operator '[]', which creates Reference object
TritSet::Reference TritSet::operator[](size_t index) {
    return Reference(*this, index);
}

TritSet::Reference::Reference(TritSet &tritSet, size_t position) : _tritSet(tritSet), _position(position) {}

//Overload operator '=' in case, when we equate to one Trit with index from TritSet another Trit
TritSet& TritSet::Reference::operator=(Trit trit) {
    _tritSet._setTrit(trit, _position);
    return this->_tritSet;
}

//Conversion operator "Trit()" overloading
TritSet::Reference::operator Trit() const {
    return _tritSet._getTrit(_position);
}

//We get the number of trits depending on the value
size_t TritSet::cardinality(Trit value) const{
    if (value == TRUE) return _true_count;
    else if(value == FALSE) return  _false_count;
    else return _unknown_count;
}


//Get the number of trits for all values ​​and put them to the unordered_map
std::unordered_map<Trit, size_t, std::hash<size_t>> TritSet::cardinality() const {
    std::unordered_map<Trit, size_t, std::hash<size_t>> unordered_map;
    unordered_map[TRUE] = _true_count;
    unordered_map[FALSE] = _false_count;
    unordered_map[UNKNOWN] = _unknown_count;
    return unordered_map;
}

void TritSet::_changeCountsOfTrits(size_t old_value, Trit new_value) {
    if (old_value == TRUE)  _true_count--;
    else if(old_value == FALSE) _false_count--;
    else _unknown_count--;

    if (new_value == TRUE)  _true_count++;
    else if(new_value == FALSE) _false_count++;
    else _unknown_count++;
}

void TritSet::_setStartCounts(Trit value, size_t size) {
    if (value == TRUE) _true_count = size;
    else if (value == FALSE) _false_count = size;
    else _unknown_count = size;
}

//Forget the values coming after last_index
void TritSet::trim(size_t last_index) {
    size_t uint_position = last_index / UINT_SIZE;

    _changeTritSetSize(uint_position + 1);
    _max_size = last_index + 1;
    _allocated_size = uint_position + 1;

    _array[uint_position] = _array[uint_position] & (~((uint)0) >> 2 * ((UINT_SIZE - 1) - ((last_index) % (UINT_SIZE - 1))));

    _logical_size = _search_last_index() + 1;
}

size_t TritSet::_search_last_index() const {
    long last_index = -1;
    for (size_t i = 0; i < _max_size; i++)
        if (_getTrit(i) != UNKNOWN)
            last_index = i;
    return last_index;
}

size_t TritSet::capacity() const {
    return _max_size;
}

void TritSet::shrink() {
    if (!_allocated_size) {
        return;
    }

    size_t last_index = _search_last_index() + 1;
    if (last_index < (_allocated_size - 1) * UINT_SIZE) {
        return;
    }

    _changeTritSetSize(last_index / (UINT_SIZE) + 1);
    _max_size = (last_index + 1);
}


