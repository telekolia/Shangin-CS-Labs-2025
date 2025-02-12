#include <iostream>
#include <clocale>
#include "mymath/mymath.hpp"
#include "myteacher/myteacher.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 1+1=";
    int rez = mymath::sum(10, 32);
    std::cout << rez << std::endl;

    std::cout << "И это ";
    if (myteacher::CheckRez(1, 1, rez)) {
        std::cout << "верно\n";
    } else {
        std::cout << "не верно\n";
    }

    return 0;
}
