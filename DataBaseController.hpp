#pragma once

#include "planet/PlanetClass.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>

namespace ReadersAndPrinters {
   const char* ReadFileNameFromStdin();
}

namespace Sort {
   enum class SortOrder : bool {
       DescendingOrder = false,
       AscendingOrder,
   };
}

enum class DBCommand : int {
   ReadDB = 1,
   WriteDBToFile,
   SortDB,
   AddElement,
   DeleteElement,
   ChangeElement,
   PrintDB,
};

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

    void WriteToFile(const char* fileName);

    void SelectionSort(Sort::SortOrder sortOrder);

    void Print();

    void AddToEnd(Planet newEl);

    void DeleteElement(unsigned int index);

    void ChangeElement(unsigned int index, Planet element);

    friend void Menu(const char* name);
};

void StartMainLoop(const char* name);
