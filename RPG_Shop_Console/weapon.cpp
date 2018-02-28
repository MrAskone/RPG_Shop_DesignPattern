#include "weapon.h"

Weapon::Weapon()
{
    m_name = "unidentified weapon";
    m_price = 0;
    m_dps = 0;
    m_attributes = {0, 0, 0, 0, 0, 0};
}

string Weapon::examineWeapon() const
{
    string description;

    switch(getAttributes()[0]){
    case 0: description =+ "An old "; break;
    case 1: description =+ "A used "; break;
    case 2: description =+ "A balanced "; break;
    case 3: description =+ "An excellent "; break;
    case 4: description =+ "A formidable "; break;
    default: description =+ "An old "; break;
    }

    switch(getAttributes()[1]){
    case 0: description = description; break;
    case 1: switch (getAttributes()[2]){
        case 0: description = description; break;
        case 1: description += "warm "; break;
        case 2: description += "fire-infused "; break;
        case 3: description += "blazing "; break;
        case 4: description += "SunFire "; break;
        default: description = description; break;
        }
    case 2: switch (getAttributes()[2]){
        case 0: description = description; break;
        case 1: description += "breezy "; break;
        case 2: description += "wind-infused "; break;
        case 3: description += "cyclonic "; break;
        case 4: description += "Kamikaze "; break;
        default: description = description; break;
        }
    case 3: switch (getAttributes()[2]){
        case 0: description = description; break;
        case 1: description += "muddy "; break;
        case 2: description += "earth-infused "; break;
        case 3: description += "seismic "; break;
        case 4: description += "Earth-Shattering "; break;
        default: description = description; break;
        }
    case 4: switch (getAttributes()[2]){
        case 0: description = description; break;
        case 1: description += "breezy "; break;
        case 2: description += "wind "; break;
        case 3: description += "cyclonic "; break;
        case 4: description += "Kamikaze "; break;
        default: description = description; break;
        }
    default: description = description; break;
    }

    description += (getName() + " which deals " + to_string(getDps()) + " damage per second.\n");
    return description;
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
