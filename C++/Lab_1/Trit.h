//
// Created by Bayramov Nidjat on 16.09.18.
//

#ifndef LAB_1_TRIT_H
#define LAB_1_TRIT_H

enum Trit {FALSE = 1, UNKNOWN = 0, TRUE = 2};

Trit operator~(Trit trit_1);
Trit operator&(Trit trit_1, Trit trit_2);
Trit operator|(Trit trit_1, Trit trit_2);

#endif //LAB_1_TRIT_H
