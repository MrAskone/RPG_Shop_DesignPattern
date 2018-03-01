#ifndef WEAPONATTRIBUTES_H
#define WEAPONATTRIBUTES_H

#include "weapon.h"


class WeaponDecorator: public Weapon
{   // if possible, make this an abstract class
public:
    WeaponDecorator( Weapon* weapon,
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
    Weapon* m_weapon;
};

class Quality: public WeaponDecorator
{
/// attribute number 0, value from 0 to 4
public:
//    Quality( Weapon* weapon, vector<int> attributeValue, vector<int> = {0} );
    Quality(Weapon* weapon/*,
                     vector<int> attributeValue*/):
        WeaponDecorator (weapon , {4}, {0})
    {}
    virtual void priceModifier();
    virtual void damageModifier();
};

class Element: public WeaponDecorator
{
public:
    Element(Weapon* weapon):
        WeaponDecorator (weapon, {2, 3}, {1 ,2}){}

};






#endif // WEAPONATTRIBUTES_H
