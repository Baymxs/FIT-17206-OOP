#include <iostream>
#include "TritSet.h"
int main() {
    TritSet set1;
    TritSet set2(5, FALSE);
    TritSet set3(10, UNKNOWN);
    TritSet set4(15, UNKNOWN);

    std::cout << "Set1 size: " << set1.size() << std::endl << "Set2 size: " << set2.size() << std::endl << "Set3 size: "
              << set3.size() << std::endl << "Set4 size: " << set4.size() << std::endl;
    set2[0] = TRUE;
}