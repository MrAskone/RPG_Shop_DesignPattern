#include "weaponattributes.h"





WeaponDecorator::WeaponDecorator(unique_ptr<Weapon> weapon,
                                 vector<int> attributeValue,
                                 vector<int> attributeNumber)
{
    m_weapon = move(weapon);

    for ( int i(0); i < attributeNumber.size(); i++ )
    {
        m_attributes[attributeNumber[i]] = attributeValue[i];
    }
    priceModifier();
    damageModifier();
}


//Quality::Quality(unique_ptr<Weapon> weapon, vector<int> attributeValue, vector<int>):
//    WeaponDecorator (move(weapon) , attributeValue, {0})
//{
//    priceModifier();
//    damageModifier();
//}

void Quality::priceModifier()
{
    if (m_attributes[0] != 0)
    {
        m_price *= 120 * m_attributes[0];
    }
}

void Quality::damageModifier()
{
    if (m_attributes[0] != 0)
    {
        m_dps *= 5 * m_attributes[0];
    }
}
