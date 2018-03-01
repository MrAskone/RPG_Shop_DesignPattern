#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
#include <QString>

using namespace std;


class Weapon
{
public:
    Weapon();

    virtual string getWeaponType() const
    {
        return m_weaponType;
    }

    virtual vector<int> getAttributes() const
    {
        return m_attributes;
    }

    virtual void setDps(int dps) { m_dps = dps; }

    virtual int getDps() const = 0;
    virtual int getPrice() const = 0;
    virtual ~Weapon()
    {
        cout << "~Weapon destroyed" << endl;
    }

    /// DOES NOT WORK
//    friend ostream &operator<<(ostream &o, Weapon *weapon)
//    {
//        return o << weapon->getName() << " which deals " << to_string(weapon->getDps()) << " damage per second." << endl;
//    }

    virtual string examineWeapon() const;

protected:
    string m_weaponType;
    vector<int> m_attributes;
    int m_dps;
    int m_price;
};


class Dagger: public Weapon
{
public:

    Dagger();
    virtual int getPrice() const { return m_price; }
    virtual int getDps() const { return m_dps; }
    virtual ~Dagger()
    {
        cout << "~Dagger destroyed" << endl;
    }
};

class Axe: public Weapon
{
public:

    Axe();
    virtual int getPrice() const { return m_price; }
    virtual int getDps() const { return m_dps; }
    virtual ~Axe()
    {
        cout << "~Axe destroyed" << endl;
    }
};

class Sword: public Weapon
{
public:

    Sword();
    virtual int getPrice() const { return m_price; }
    virtual int getDps() const { return m_dps; }
    virtual ~Sword()
    {
        cout << "~Sword destroyed" << endl;
    }
};

class Staff: public Weapon
{
public:

    Staff();
    virtual int getPrice() const { return m_price; }
    virtual int getDps() const { return m_dps; }
    virtual ~Staff()
    {
        cout << "~Staff destroyed" << endl;
    }
};

class WeaponFactory{
public:
    enum WeaponType {
        DaggerType,
        AxeType,
        SwordType,
        StaffType
    };

    static Weapon* baseWeapon(WeaponType weaponType)
    {
        switch (weaponType) {
        case DaggerType:    return new Dagger();
        case AxeType:       return new Axe();
        case SwordType:     return new Sword();
        case StaffType:     return new Staff();
        }
        throw "invalid weapon type.";
    }
};




#endif // WEAPON_H
