#include "planet/PlanetClass.hpp"
#include "DataBaseController.hpp"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

namespace {
    const unsigned int kDefaultCapacity = 8;
    const int kBufferLength = 512;
}

namespace DB {
void DBArray::IncreaceCapacity() {
    capacity *= 2;
    Planet::Planet* temp = new Planet::Planet[capacity];
    std::copy(ptr, ptr + size, temp);

    delete[] ptr;
    ptr = temp;
}


DBArray::DBArray() {
    capacity = kDefaultCapacity;
    size = 0;
    ptr = new Planet::Planet[capacity];
}

DBArray::DBArray(const char* fileName) {
    ReadFromFile(fileName);
}

DBArray::~DBArray() {
    delete[] ptr;
}

void DBArray::ReadFromFile(const char* fileName) {
    std::ifstream in(fileName, std::ios::binary);
    if (!in.is_open()) {
        std::cout << "НЕ УДАЛОСЬ ОТКРЫТЬ \"" << fileName << "\"\n";
        return;
    }

    int count;
    in >> count;
    capacity = count;
    ptr = new Planet::Planet[count];
    for (int i = 0; i < count; ++i) {
        in >> ptr[i];
        ++size;
    }

    in.close();
}

void DBArray::WriteToFile(char* fileName) {

    if (!fileName) {
        return;
    }
    std::ofstream out(fileName, std::ios::binary);
    if (!out.is_open()) {
        std::cout << "НЕ УДАЛОСЬ ОТКРЫТЬ \"" << fileName << "\"\n";
        return;
    }

    std::cout << size << '\n';
    for (unsigned int i = 0; i < size; ++i) {
        std::cout << ptr[i];
    }

    out.close();
}

void DBArray::Print() {
    std::cout << size << '\n';
    for (unsigned int i = 0; i < size; ++i) {
        std::cout << ptr[i];
    }
}

void DBArray::AddToEnd(Planet::Planet newEl) {
    if (++size > capacity) {
        IncreaceCapacity();
    }

    ptr[size - 1] = newEl;
}

void DBArray::ChangeElement(unsigned int index, Planet::Planet element) {
    if (index > size) {
        std::cout << "Неверно указан номер изменяемого эллемента\n";
        return;
    }

    ptr[index - 1] = element;
}

void StartDBController(const char* name) {
    DBArray a(name);
    a.Print();
}

}
