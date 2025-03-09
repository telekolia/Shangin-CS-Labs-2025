#include "PlanetClass.hpp"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

namespace {
const int kBufferLength = 128;
}

namespace Planet {
class Planet {
 private:
    char* name;
    int diameter;
    bool life;
    int satellites;

 public:
    Planet() {
        name = new char[1];
        name[0] = '\0';

        diameter = 0;
        life = false;
        satellites = 0;
    }

    Planet(const char* n1, int diam1 = 1000, bool life1 = false, int satel1 = 0) {
        name = new char[std::strlen(n1) + 1];
        std::memcpy(name, n1, std::strlen(n1));
        name[std::strlen(n1)] = '\0';

        diameter = diam1;
        life = life1;
        satellites = satel1;
    }

    Planet(const Planet& obj) {
        name = new char[std::strlen(obj.name) + 1];
        std::memcpy(name, obj.name, std::strlen(obj.name));
        name[std::strlen(obj.name)] = '\0';

        diameter = obj.diameter;
        life = obj.life;
        satellites = obj.satellites;
    }

    ~Planet() {
        delete[] name;
    }

    Planet& operator =(const Planet& obj) {
        if (this == &obj) {
            return *this;
        }

        setName(obj.name);
        setDiameter(obj.diameter);
        setLife(obj.life);
        setSatellites(obj.satellites);
    }

    friend std::ostream& operator <<(std::ostream& out, const Planet& obj) {
        out << obj.name << ' ' << obj.diameter << ' ' << obj.life << ' ' << obj.satellites;
        return out;
    }

    friend std::ofstream& operator <<(std::ofstream& out, const Planet& obj) {
        out << obj.name << ' ' << obj.diameter << ' ' << obj.life << ' ' << obj.satellites;
        return out;
    }

    friend std::istream& operator >>(std::istream& in, Planet& obj) {
        char name[kBufferLength] {};
        in >> name >> obj.diameter >> obj.life >> obj.satellites;
        obj.setName(name);
        return in;
    }

    friend std::ifstream& operator >>(std::ifstream& in, Planet& obj) {
        char name[kBufferLength] {};
        in >> obj.name >> obj.diameter >> obj.life >> obj.satellites;
        obj.setName(name);
        return in;
    }

    char* getName() {
        return name;
    }

    int getDiameter() {
        return diameter;
    }

    bool getLife() {
        return life;
    }

    int getSatellites() {
        return satellites;
    }

    void setName(const char* n1) {
        delete[] name;
        if (!n1) {
            name = new char[1];
            name[0] = '\0';
            return;
        }
        name = new char[std::strlen(n1) + 1];
        std::memcpy(name, n1, std::strlen(n1));
        name[std::strlen(n1)] = '\0';
    }

    void setDiameter(const int& diam1) {
        diameter = diam1;
    }

    void setLife(const bool& life1) {
        life = life1;
    }

    void setSatellites(const int& satel1) {
        satellites = satel1;
    }

    bool operator ==(const Planet& obj) {
        if (this->diameter == obj.diameter && this->life == obj.life && this->satellites == obj.satellites) {
            return true;
        }
        return false;
    }

    bool operator !=(const Planet& obj) {
        return !(*this == obj);
    }

    bool operator >(const Planet& obj) {
        return (this->diameter > obj.diameter);
    }

    bool operator <(const Planet& obj) {
        return (this->diameter < obj.diameter);
    }

};

}
