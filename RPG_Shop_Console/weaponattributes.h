#ifndef WEAPONATTRIBUTES_H
#define WEAPONATTRIBUTES_H

#include "weapon.h"


class WeaponDecorator: public Weapon
{   // if possible, make this an abstract class
public:
    WeaponDecorator( unique_ptr<Weapon> weapon,
                     vector<int> attributeValue,
                     vector<int> attributeNumber );
    virtual void priceModifier() {}
    virtual void damageModifier() {}    // this could be made a pure virtual to make the class abstract.
                                        // and insure this class cannot be instantiated. But oh well, I'm still learning.
    virtual int getDps() const { return m_dps; }
    virtual int getPrice() const {return m_price; }
    virtual ~WeaponDecorator()
    {
        cout << "~WeaponDecorator()\n";
    }
protected:
    unique_ptr<Weapon> m_weapon;
};

class Quality: public WeaponDecorator
{
/// attribute number 0, value from 0 to 4
public:
//    Quality( unique_ptr <Weapon> weapon, vector<int> attributeValue, vector<int> = {0} );
    Quality(unique_ptr<Weapon> weapon/*,
                     vector<int> attributeValue*/):
        WeaponDecorator (move(weapon) , {4}, {0})
    {}
    virtual void priceModifier();
    virtual void damageModifier();
};

class Element: public WeaponDecorator
{
public:
    Element(unique_ptr<Weapon> weapon):
        WeaponDecorator (move(weapon), {2, 3}, {1 ,2}){}

};






#endif // WEAPONATTRIBUTES_H
