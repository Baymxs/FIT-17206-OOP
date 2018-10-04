//
// Created by Bayramov Nidjat on 13.09.18.
//

#include "Trit.h"

//Operator '~' overloading for Trit
Trit operator~(Trit trit) {
    if (trit == TRUE) return FALSE;
    else if (trit == FALSE) return TRUE;
    else return UNKNOWN;

}

//Operator '&' overloading for Trit
Trit operator& (Trit trit_1, Trit trit_2) {
    if (trit_1 == FALSE || trit_2 == FALSE) return FALSE;
    else if (trit_1 == UNKNOWN || trit_2 == UNKNOWN) return UNKNOWN;
    else return  TRUE;
}

//Operator '|' overloading for Trit
Trit operator| (Trit trit_1, Trit trit_2) {
    if (trit_1 == TRUE || trit_2 == TRUE) return TRUE;
    else if (trit_1 == UNKNOWN || trit_2 == UNKNOWN) return UNKNOWN;
    else return FALSE;
}

