#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>

namespace Planet {
class Planet {
 private:
    char* name;
    int diameter;
    bool life;
    int satellites;
 public:
    Planet();

    Planet(const char* name, int diam1 = 1000, bool life1 = false, int satel1 = 0);

    Planet(const Planet& obj);

    ~Planet();

    Planet& operator =(const Planet& obj);

    friend std::ostream& operator <<(std::ostream& out, const Planet& obj);

    friend std::ofstream& operator <<(std::ofstream& out, const Planet& obj);

    friend std::istream& operator >>(std::istream& in, Planet& obj);

    friend std::ifstream& operator >>(std::ifstream& in, Planet& obj);

    char* getName() const;

    int getDiameter() const;

    bool getLife() const;

    int getSatellites() const;

    void setName(const char* n1);

    void setDiameter(const int& diam1);

    void setLife(const bool& life1);

    void setSatellites(const int& satel1);

    bool operator ==(const Planet& obj);

    bool operator !=(const Planet& obj);

    bool operator >(const Planet& obj);

    bool operator <(const Planet& obj);

};

}
