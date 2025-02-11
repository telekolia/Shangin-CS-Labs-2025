#ifndef MPrinter_H
#define MPrinter_H

namespace MPrinter {
struct PrintFormat {
    bool IsExpFormat = true;
    int precision = 0;
};

void PrintM(int N, int M, double** A, PrintFormat format);

}  // namespace MPrinter

#endif // MPrinter_H
