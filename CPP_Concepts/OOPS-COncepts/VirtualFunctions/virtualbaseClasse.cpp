/**
 * @file virtualbaseClasse.cpp
 * @author Abhishek
 * @brief Here we discuss about the following:
 * 1- Diamond problem.
 * **NOTE**
 * There are a few rules to this virtual base classes:
 * 1- virtual base classes are always created before non-virtual base classes, which ensures all bases get 
 * created before their derived classes.
 * 
 * 2- note that the Scanner and Printer constructors still have calls to the PoweredDevice constructor. 
 * When creating an instance of Copier, these constructor calls are simply ignored because Copier is responsible 
 * for creating the PoweredDevice, not Scanner or Printer. However, if we were to create an instance of Scanner 
 * or Printer, those constructor calls would be used, and normal inheritance rules apply.
 * 
 * 3- If a class inherits one or more classes that have virtual parents, the most derived class is responsible for constructing 
 * the virtual base class. In this case, Copier inherits Printer and Scanner, both of which have a 
 * PoweredDevice virtual base class. Copier, the most derived class, is responsible for creation of PoweredDevice. 
 * Note that this is true even in a single inheritance case: if Copier singly inherited from Printer, and Printer 
 * was virtually inherited from PoweredDevice, Copier is still responsible for creating PoweredDevice.
 * 
 * 4- all classes inheriting a virtual base class will have a virtual table, even if they would normally 
 * not have one otherwise, and thus instances of the class will be larger by a pointer.
 *  Because Scanner and Printer derive virtually from PoweredDevice, Copier will only be one PoweredDevice 
 * subobject. Scanner and Printer both need to know how to find that single PoweredDevice subobject, so they can 
 * access its members (because after all, they are derived from it). This is typically done through some virtual 
 * table magic (which essentially stores the offset from each subclass to the PoweredDevice subobject).
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
		std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner: virtual public PoweredDevice
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice{ power }
    {
		std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer: virtual public PoweredDevice
{
public:
    Printer(int printer, int power)
        : PoweredDevice{ power }
    {
		std::cout << "Printer: " << printer << '\n';
    }
};

class Copier: public Scanner, public Printer
{
public:
    /// In case of Virtual Base class, in order to initialize the base class the classes that have the shared copy
    /// cannot initialize it, so it is upto the most derived class.
    /// **This is the only time when the derived class is allowed to call the non-immediate parent constructor.
    Copier(int scanner, int printer, int power)
        : PoweredDevice{ power }, Scanner{ scanner, power }, Printer{ printer, power }
    {
    }
};

int main(int argc, char const *argv[])
{
    /// here two copies of the Base class(PoweredDevice) will be created, one by Printer and the other by Scanner.
    Copier copy(1, 2, 3);
    return 0;
}
