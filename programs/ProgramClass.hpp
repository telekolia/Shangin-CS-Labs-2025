#ifndef PROGRAM_H
#define PROGRAM_H

#include <fstream>
#include <iomanip>
#include <iostream>

class Program {
 private:
    char* name;
    int version;
    int size;

 public:
    Program();

    Program(const char* name, int vers1 = 0, int size1 = 0);

    Program(const Program& obj);

    ~Program();

    Program& operator=(const Program& obj);

    friend std::ostream& operator<<(std::ostream& out, const Program& obj);

    friend std::istream& operator>>(std::istream& in, Program& obj);

    friend std::ifstream& operator>>(std::ifstream& in, Program& obj);

    char* getName() const;

    int getVersion() const;

    bool getSize() const;

    void setName(const char* n1);

    void setVersion(const int& vers1);

    void setSize(const int& size1);

    bool operator==(const Program& obj);

    bool operator!=(const Program& obj);

    bool operator>(const Program& obj);

    bool operator<(const Program& obj);
};

#endif //PROGRAM_H
