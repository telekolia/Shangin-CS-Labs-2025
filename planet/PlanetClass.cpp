#include "PlanetClass.hpp"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

namespace {
const int kBufferLength = 128;
}

Planet::Planet() {
    name = new char[1];
    name[0] = '\0';

    diameter = 0;
    life = false;
    satellites = 0;
}

Planet::Planet(const char* name, int diam1, bool life1, int satel1) {
    this->name = new char[std::strlen(name) + 1];
    std::memcpy(this->name, name, std::strlen(name));
    this->name[std::strlen(name)] = '\0';

    diameter = diam1;
    life = life1;
    satellites = satel1;
}

Planet::Planet(const Planet& obj) {
    name = new char[std::strlen(obj.name) + 1];
    std::memcpy(name, obj.name, std::strlen(obj.name));
    name[std::strlen(obj.name)] = '\0';

    diameter = obj.diameter;
    life = obj.life;
    satellites = obj.satellites;
}

Planet::~Planet() {
    delete[] name;
}

Planet& Planet::operator=(const Planet& obj) {
    if (this == &obj) {
        return *this;
    }

    setName(obj.name);
    setDiameter(obj.diameter);
    setLife(obj.life);
    setSatellites(obj.satellites);
}

std::ostream& operator<<(std::ostream& out, const Planet& obj) {
    out << obj.name << ' ' << obj.diameter << ' ' << obj.life << ' ' << obj.satellites << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Planet& obj) {
    char name[kBufferLength]{};
    in >> name >> obj.diameter >> obj.life >> obj.satellites;
    obj.setName(name);
    return in;
}

std::ifstream& operator>>(std::ifstream& in, Planet& obj) {
    char name[kBufferLength]{};
    in >> name >> obj.diameter >> obj.life >> obj.satellites;
    obj.setName(name);
    return in;
}

char* Planet::getName() const {
    return name;
}

int Planet::getDiameter() const {
    return diameter;
}

bool Planet::getLife() const {
    return life;
}

int Planet::getSatellites() const {
    return satellites;
}

void Planet::setName(const char* name) {
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

void Planet::setDiameter(const int& diameter) {
    this->diameter = diameter;
}

void Planet::setLife(const bool& life) {
    this->life = life;
}

void Planet::setSatellites(const int& satellites) {
    this->satellites = satellites;
}

bool Planet::operator==(const Planet& obj) {
    if (this->diameter == obj.diameter) {
        return true;
    }
    return false;
}

bool Planet::operator!=(const Planet& obj) {
    return !(*this == obj);
}

bool Planet::operator>(const Planet& obj) {
    return (this->diameter > obj.diameter);
}

bool Planet::operator<(const Planet& obj) {
    return (this->diameter < obj.diameter);
}
