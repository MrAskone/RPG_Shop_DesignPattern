#include "weaponattributes.h"





WeaponDecorator::WeaponDecorator(Weapon* weapon,
                                 vector<int> attributeValue,
                                 vector<int> attributeNumber)
{
    m_weapon = move(weapon);

    for ( int i(0); i < attributeNumber.size(); i++ )
    {
        m_attributes[attributeNumber[i]] = attributeValue[i];
    }

    for (int attribute : m_attributes)
    {
        cout << attribute << endl;
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
        m_weapon->setDps( getDps() * 5 * m_weapon->getAttributes()[0]);
    }
}
