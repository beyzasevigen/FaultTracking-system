// ship.h
#ifndef SHIP_H
#define SHIP_H

#include <string>

using namespace std;

/*enum ShipDepartmentType {
    MOTOR,
    GOVDE,
    YAG_TANKI,
    SU_TANKI,
    // ... diğer gemi bölüm tipleri
};*/

class Ship {

public:
    Ship(int id, const string& name);

    // Getter ve Setter fonksiyonları
    int getShipID() const;
    void setShipID(int id);

    const string& getShipName() const;
    void setShipName(const string& name);

    // ShipDepartmentType getDepartmentType() const;
    // void setDepartmentType(ShipDepartmentType type);

    int getWaterTemp() const;
    void setWaterTemp(int temp);

    int getWaterLevel() const;
    void setWaterLevel(int level);

    int getOilPressure() const;
    void setOilPressure(int pressure);

    // ... diğer fonksiyonlar

private:
    int shipID;
    string shipName;
    // ShipDepartmentType departmentType; // Enum kullanmak isterseniz, ayrı bir enum sınıfı oluşturabilirsiniz.
    int waterTemp;
    int waterLevel;
    int oilPressure;

};

#endif // SHIP_H
