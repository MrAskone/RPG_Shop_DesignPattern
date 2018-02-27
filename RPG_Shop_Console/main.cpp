#include <QCoreApplication>
#include <weapon.h>
#include <QDebug>

unique_ptr<Weapon> weaponCreate(WeaponFactory::WeaponType weaponType)
{
    unique_ptr<Weapon> weapon = WeaponFactory::baseWeapon(weaponType);
//    cout << weapon;   operator overload not working
    return weapon;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    unique_ptr<Weapon> weapon1 = weaponCreate(WeaponFactory::DaggerType);
    cout << weapon1->examineWeapon();

    weapon1 = weaponCreate(WeaponFactory::StaffType);
    cout << weapon1->examineWeapon();

    return a.exec();
}
