#include "DataBaseController.hpp"
#include "planet/PlanetClass.hpp"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

namespace {
const unsigned int kDefaultCapacity = 8;
const int kBufferLength = 512;
}  // namespace

namespace ReadersAndPrinters {
void PrintMenu() {
    std::cout << "Программа управляет базой данных из выбранного файла\n"
                << "1. чтение БД из файла\n"
                << "2. запись БД в файл\n"
                << "3. сортировка БД\n"
                << "4. добавление нового объекта в БД\n"
                << "5. удаление объекта из БД\n"
                << "6. редактирование БД\n"
                << "7. вывод БД на экран\n"
                << "Выберите интересующий вас метод решения: ";
}

DBCommand ReadDBCommandFromStdin() {
    int com {};
    std::cin >> com;
    return static_cast<DBCommand>(com);
}

const char* ReadFileNameFromStdin() {
    std::cout << "Введите путь до файла из папки запуска: ";
    char name[kBufferLength];
    std::cin >> name;
    return name;
}

Planet ReadPlanetFromStdin() {
    std::cout << "Введите значение всех полей класса \"Planet\" (имя, диаметер, жизнь, спутники): ";
    Planet newPlanet;
    std::cin >> newPlanet;
    return newPlanet;
}

int ReadElementID() {
    std::cout << "Введите ID эллемента: ";
    int id;
    std::cin >> id;
    return id;
}

Sort::SortOrder ReadSortOrderFromStdin() {
    std::cout << "Введите значение порядок сортировки(0 - по убыванию, 1 - по возрастанию): ";
    bool order;
    std::cin >> order;
    return static_cast<Sort::SortOrder>(order);
}

}

namespace Sort {
void Swap(Planet* firstElementptr, Planet* secondElementptr) {
    Planet temp (*secondElementptr);
    *secondElementptr = *firstElementptr;
    *firstElementptr = temp;
}

}

void DBArray::IncreaceCapacity() {
    capacity *= 2;
    Planet* temp = new Planet[capacity];
    std::copy(ptr, ptr + size, temp);

    delete[] ptr;
    ptr = temp;
}

DBArray::DBArray() {
    capacity = kDefaultCapacity;
    size = 0;
    ptr = new Planet[capacity];
}

DBArray::DBArray(const char* fileName) {
    capacity = kDefaultCapacity;
    size = 0;
    ptr = new Planet[capacity];
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

    delete[] ptr;

    int count;
    in >> count;
    capacity = count;
    ptr = new Planet[count];
    for (int i = 0; i < count; ++i) {
        in >> ptr[i];
        ++size;
    }

    in.close();
    std::cout << "Данные считаны\n";
}

void DBArray::WriteToFile(const char* fileName) {
    if (!fileName) {
        return;
    }
    std::ofstream out(fileName, std::ios::binary | std::ios::trunc);
    if (!out.is_open()) {
        std::cout << "НЕ УДАЛОСЬ ОТКРЫТЬ \"" << fileName << "\"\n";
        return;
    }

    out << size << '\n';
    for (unsigned int i = 0; i < size; ++i) {
        out << ptr[i];
    }

    out.close();
    std::cout << "Изменения сохранены\n";
}

void DBArray::SelectionSort(Sort::SortOrder sortOrder) {
    int extremumElementIndex = 0;
    for (int j = 0; j < size - 1; ++j) {
        extremumElementIndex = j;
        for (int i = j + 1; i < size; ++i) {
            if ((ptr[i] < ptr[extremumElementIndex]) == (sortOrder == Sort::SortOrder::AscendingOrder)) {
                extremumElementIndex = i;
            }
        }

        if (j != extremumElementIndex) {
            Sort::Swap(&ptr[j], &ptr[extremumElementIndex]);
        }
    }
}

void DBArray::Print() {
   std::cout << size << '\n';
    for (unsigned int i = 0; i < size; ++i) {
        std::cout << ptr[i];
    }
}

void DBArray::AddToEnd(Planet newEl) {
    if (size >= capacity) {
        IncreaceCapacity();
    }

    ptr[size] = newEl;
    ++size;
}

void DBArray::DeleteElement(unsigned int index) {
    if (index > size) {
        std::cout << "УДАЛЕНИЕ НЕ СУЩЕСТВУЮЩЕГО ЭЛЕМЕНТА\n";
        return;
    } else if (index == size) {
        --size;
        return;
    }
    for (unsigned i = index; i < size; ++i) {
        ptr[i - 1] = ptr[i];
    }
    --size;

}

void DBArray::ChangeElement(unsigned int index, Planet element) {
    if (index > size) {
        std::cout << "Неверно указан номер изменяемого эллемента\n";
        return;
    }

    ptr[index - 1] = element;
}

void Menu(const char* name) {
    DBArray a(name);
    std::cout << "Размер массива в который записана БД: " << a.capacity << '\n';
    std::cout << "Размер БД: " << a.size << '\n';
    ReadersAndPrinters::PrintMenu();
    DBCommand com = ReadersAndPrinters::ReadDBCommandFromStdin();
    switch (com) {
    case DBCommand::ReadDB:
        a.ReadFromFile(ReadersAndPrinters::ReadFileNameFromStdin());
        break;
    case DBCommand::WriteDBToFile:
        a.WriteToFile(ReadersAndPrinters::ReadFileNameFromStdin());
        break;
    case DBCommand::SortDB:
        a.SelectionSort(ReadersAndPrinters::ReadSortOrderFromStdin());
        break;
    case DBCommand::AddElement:
        a.AddToEnd(ReadersAndPrinters::ReadPlanetFromStdin());
        break;
    case DBCommand::DeleteElement:
        a.DeleteElement(ReadersAndPrinters::ReadElementID());
        break;
    case DBCommand::ChangeElement:
        a.ChangeElement(ReadersAndPrinters::ReadElementID(), ReadersAndPrinters::ReadPlanetFromStdin());
        break;
    case DBCommand::PrintDB:
        a.Print();
    default:
        break;
    }

    a.WriteToFile(name);
}

void StartDBController(const char* name) {
    Menu(name);
}

char ReadExtinctionKeyFormStdin() {
    std::cout << "\nЧтобы продолжить работу напишите \'y\', в ином случае введите любой символ для завершения: ";
    char extinctionKey = 0;
    std::cin >> extinctionKey;
    return extinctionKey;
}

bool ExecuteExtinctionKey() {
    if (ReadExtinctionKeyFormStdin() == 'y') {
        return true;
    } else {
        return false;
    }
}

void StartMainLoop(const char* name) {
    bool extinctionKey = true;
    while (extinctionKey) {
        StartDBController(name);
        extinctionKey = ExecuteExtinctionKey();
    }
    std::cout << "\n";
}
