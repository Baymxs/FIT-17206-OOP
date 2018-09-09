#include "module1.h"
#include "module2.h"
#include <iostream>

int main(int argc, char** argv) {
    std::cout <<  "Hello world!" << "\n";

    std::cout << Module1::getMyName() << "\n";
    std::cout << Module2::getMyName() << "\n";

    using namespace Module1;
    std::cout << getMyName() << "\n"; // (A)
    std::cout << Module2::getMyName() << "\n";

    //using namespace Module2; // (B)
    //std::cout << getMyName() << "\n"; // COMPILATION ERROR (C)

    using Module2::getMyName;
    std::cout << getMyName() << "\n"; // (D)
    std::cout << getMyName() << "\n";
}


// 1)Да, в директории СMakeFiles/Task_0a.dir существуют три объектных файлов main.cpp.o, module1.cpp.o, module2.cpp.o
// 2)Проверено
// 3) (A) getMyName из пространства имен Module1, т.е "John", потому что у нас задано пространство имен Module1
//    (D) getMyName из простраснтва имен Module2, т.е "James", потому что строкой ранее мы добавляем в область видимости
//        1 идентификатор (перекрываем getMyName из области видимости Module1)
// 4)Раскомментирование действительно приводит к ошибке, т.к мы добавляем в область видимости все идентификаторы из
//   пространства имен Module1 и Module2, а в этих пространствах имен объявлены функции с одинаковыми именами, мы получили
//   конфликт имен
//   Чтобы устранить эту ошибку, можно во втором случае обращаться к функции getMyName след. образом: Module2::getMyName.
// 5)Сделано
// 6)Использовать using namespace std