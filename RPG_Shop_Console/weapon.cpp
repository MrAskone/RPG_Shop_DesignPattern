#include "weapon.h"

Weapon::Weapon()
{
    m_name = "unidentified weapon";
    m_price = 0;
    m_dps = 0;
}

Dagger::Dagger()
{
    m_name = "dagger";
    m_price = 100;
    m_dps = 10;
}

Axe::Axe()
{
    m_name = "axe";
    m_price = 200;
    m_dps = 15;
}


Sword::Sword()
{
    m_name = "sword";
    m_price = 150;
    m_dps = 12;
}



Staff::Staff()
{
    m_name = "staff";
    m_price = 150;
    m_dps = 8;
}
