#include <QCoreApplication>
#include <weaponattributes.h>
#include <QDebug>


Weapon *weaponCreate(WeaponFactory::WeaponType weaponType)
{
    Weapon *weapon = WeaponFactory::baseWeapon(weaponType);
//    cout << weapon;   operator overload not working
    return weapon;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto weapon1 = weaponCreate(WeaponFactory::DaggerType);
    cout << weapon1->examineWeapon();

    weapon1 = new Quality(weapon1);

    cout << weapon1->examineWeapon();

    weapon1 = new Element(weapon1);

    cout << weapon1->examineWeapon();


    weapon1 = weaponCreate(WeaponFactory::StaffType);

    cout << weapon1->examineWeapon();

    return a.exec();
}

//class IiceCream
//{
//public:
//    virtual void Make() = 0;
//    virtual ~IiceCream() { }

//};

//class SimpleIceCream: public IiceCream
//{
//public:
//    virtual void Make()
//    {
//        std::cout<<"\n milk + sugar +  Ice cream Powder";
//    }


//};

//class IceCreamDecorator: public IiceCream
//{

//public:
//    IceCreamDecorator(IiceCream& decorator):m_Decorator(decorator)
//    {

//    }

//    virtual void Make()
//    {
//        m_Decorator.Make();
//    }
//    private:
//    IiceCream& m_Decorator;
//};

//class WithFruits : public IceCreamDecorator
//{

//public:
//     WithFruits(IiceCream& decorator):IceCreamDecorator(decorator)
//     {

//     }
//     virtual void Make()
//     {
//         IceCreamDecorator::Make();
//         std::cout<<" + Fruits";
//     }

//};

//class WithNuts : public IceCreamDecorator
//{

//public:
//    WithNuts(IiceCream& decorator):IceCreamDecorator(decorator)
//    {

//    }

//    virtual void Make()
//    {
//        IceCreamDecorator::Make();
//        std::cout<<" + Nuts";
//    }

//};

//class WithWafers : public IceCreamDecorator
//{

//public:
//    WithWafers(IiceCream& decorator):IceCreamDecorator(decorator)
//    {

//    }

//    virtual void Make()
//    {
//        IceCreamDecorator::Make();
//        std::cout<<" + Wafers";
//    }

//};

//int main()
//{
//    IiceCream* pIceCreamSimple = new SimpleIceCream();
//    pIceCreamSimple->Make();

//    IiceCream* pIceCreamFruits = new WithFruits(*pIceCreamSimple);
//    pIceCreamFruits->Make();

//    IiceCream* pIceCreamNuts   = new WithNuts(*pIceCreamFruits);
//    pIceCreamNuts->Make();

//    IiceCream* pIceCreamWafers = new WithWafers(*pIceCreamNuts);
//    pIceCreamWafers->Make();

//    delete pIceCreamSimple;
//    delete pIceCreamFruits;
//    delete pIceCreamNuts;
//    delete pIceCreamWafers;

//    return 0;
//}
