#pragma once

#include "planet/PlanetClass.hpp"

#include <iostream>
#include <iomanip>
#include <fstream>

namespace {
    const unsigned int kDefaultcapacity = 8;
}

namespace DB {
    class DBArray {
        private:
         Planet::Planet* ptr;
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

         void AddToEnd(Planet::Planet newEl);

         void ChangeElement(unsigned int index, Planet::Planet element);
    };

    void StartDBController(const char* name);
}
