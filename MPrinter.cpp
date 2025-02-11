#include "MPrinter.hpp"

#include <iostream>
#include <iomanip>

namespace {
const int GoogleOutputWidth = 80;

}  // namespace

namespace MPrinter {
void PrintM(int N, int M, double** A, PrintFormat format) {
    if (!*(A)) {
        std::cout << "Введённый массив пуст\n";
        return;
    }

    std::cout << "N = " << N << "\nM = " << M << '\n';
    int columnWidth = 0;
    if (format.IsExpFormat) {
        std::cout << "Экспоненциальный формат вывода\n";
        std::cout << std::scientific;
        columnWidth = 13;
    } else {
        std::cout << "Вывод с " << format.precision << " знаками после запятой\n";
        std::cout << std::setprecision(format.precision) << std::fixed;
        columnWidth = format.precision + 3;
    }
    std::cout << std::right << "--------------------------------------------------------------------------------\n";
    std::cout << "--------------------------------------------------------------------------------\n";

    int numberOfColums = GoogleOutputWidth / columnWidth;

    int firstColumnIndex = 0;
    int temp = 0;
    int lastColumIndex = temp + numberOfColums;
    while (firstColumnIndex < N) {
        for (int j = 0; j < M; ++j) {
            for (int i = firstColumnIndex; i < N && i < lastColumIndex; ++i) {
                std::cout << std::setw(columnWidth-1) << A[i][j] << ' ';
                temp = i;
            }
            std::cout << '\n';
        }
        std::cout << "--------------------------------------------------------------------------------\n";
        ++temp;
        lastColumIndex = temp + numberOfColums;
        firstColumnIndex = temp;
    }
    std::cout << "--------------------------------------------------------------------------------\n";
}

}
