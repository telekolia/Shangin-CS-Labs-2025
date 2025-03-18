#include "ProgramClass.hpp"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

namespace {
const int kBufferLength = 128;
}

Program::Program() {
    name = new char[1];
    name[0] = '\0';

    version = 0;
    size = 0;
}

Program::Program(const char* name, int vers1, int size1) {
    this->name = new char[std::strlen(name) + 1];
    std::memcpy(this->name, name, std::strlen(name));
    this->name[std::strlen(name)] = '\0';

    version = vers1;
    size = size1;
}

Program::Program(const Program& obj) {
    name = new char[std::strlen(obj.name) + 1];
    std::memcpy(name, obj.name, std::strlen(obj.name));
    name[std::strlen(obj.name)] = '\0';

    version = obj.version;
    size = obj.size;
}

Program::~Program() {
    delete[] name;
}

Program& Program::operator=(const Program& obj) {
    if (this == &obj) {
        return *this;
    }

    setName(obj.name);
    setVersion(obj.version);
    setSize(obj.size);

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Program& obj) {
    out << obj.name << ' ' << obj.version << ' ' << obj.size << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Program& obj) {
    char name[kBufferLength]{};
    in >> name >> obj.version >> obj.size;
    obj.setName(name);
    return in;
}

std::ifstream& operator>>(std::ifstream& in, Program& obj) {
    char name[kBufferLength]{};
    in >> name >> obj.version >> obj.size;
    obj.setName(name);
    return in;
}

char* Program::getName() const {
    return name;
}

int Program::getVersion() const {
    return version;
}

bool Program::getSize() const {
    return size;
}

void Program::setName(const char* name) {
    delete[] this->name;
    if (!name) {
        this->name = new char[1];
        this->name[0] = '\0';
        return;
    }
    this->name = new char[std::strlen(name) + 1];
    std::memcpy(this->name, name, std::strlen(name));
    this->name[std::strlen(name)] = '\0';
}

void Program::setVersion(const int& version) {
    this->version = version;
}

void Program::setSize(const int& size) {
    this->size = size;
}

bool Program::operator==(const Program& obj) {
    if (this->size == obj.size) {
        return true;
    }
    return false;
}

bool Program::operator!=(const Program& obj) {
    return !(*this == obj);
}

bool Program::operator>(const Program& obj) {
    return (this->size > obj.size);
}

bool Program::operator<(const Program& obj) {
    return (this->size < obj.size);
}
