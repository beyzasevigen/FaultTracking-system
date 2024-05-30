// ship.cpp
#include "../header/ship.hpp"

using namespace std;

Ship::Ship(int id, const string& name)
    : shipID(id), shipName(name), waterTemp(0), waterLevel(0), oilPressure(0) {}

int Ship::getShipID() const {
    return shipID;
}

void Ship::setShipID(int id) {
    shipID = id;
}

const string& Ship::getShipName() const {
    return shipName;
}

void Ship::setShipName(const string& name) {
    shipName = name;
}

int Ship::getWaterTemp() const {
    return waterTemp;
}

void Ship::setWaterTemp(int temp) {
    waterTemp = temp;
}

int Ship::getWaterLevel() const {
    return waterLevel;
}

void Ship::setWaterLevel(int level) {
    waterLevel = level;
}

int Ship::getOilPressure() const {
    return oilPressure;
}

void Ship::setOilPressure(int pressure) {
    oilPressure = pressure;
}

// Diğer fonksiyonların tanımları buraya eklenebilir
