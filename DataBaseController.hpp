#pragma once

#include "planet/PlanetClass.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>

namespace {
const unsigned int kDefaultcapacity = 8;
}

class DBArray {
 private:
    Planet* ptr;
    unsigned int size;
    unsigned int capacity;

    void IncreaceCapacity();

 public:
    DBArray();

    DBArray(const char* fileName);

    ~DBArray();

    void ReadFromFile(const char* fileName);

    void WriteToFile(char* fileName);

    void Print();

    void AddToEnd(Planet newEl);

    void ChangeElement(unsigned int index, Planet element);
};

void StartDBController(const char* name);
