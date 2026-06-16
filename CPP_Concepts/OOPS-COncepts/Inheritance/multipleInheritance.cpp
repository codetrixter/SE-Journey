/**
 * @file multipleInheritance.cpp
 * @author Abhishek
 * @brief Here we discuss the concept of multiple inheritance 
 * @version 0.1
 * @date 2022-06-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

class USBDevice
{
private:
    long m_id {};

public:
    USBDevice(long id)
        : m_id { id }
    {
    }

    long getID() const { return m_id; }
};

class NetworkDevice
{
private:
    long m_id {};

public:
    NetworkDevice(long id)
        : m_id { id }
    {
    }

    long getID() const { return m_id; }
};

/// Derived class WirelessAdapter is inherited from two base classes USBDevice and Network Device. which is multiple 
/// inheritance.
class WirelessAdapter: public USBDevice, public NetworkDevice
{
public:
    WirelessAdapter(long usbId, long networkId)
        : USBDevice { usbId }, NetworkDevice { networkId }
    {
    }
};

int main()
{
    WirelessAdapter c54G { 5442, 181742 };
    /// std::cout << c54G.getID(); // Which getID() do we call?: request for getId() call is ambiguous.
    std::cout << c54G.USBDevice::getID() << std::endl; // call getID() of USBDevice

    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Multiple inheritance** | `class WirelessAdapter: public USBDevice, public NetworkDevice` |
| 2 | **Ambiguity resolution** | `c54G.USBDevice::getID()` — scope resolution |
| 3 | **Diamond problem potential** | Both bases have `m_id` and `getID()` |

### 🔄 Alternatives & Modern C++ Idioms:
- Prefer composition over multiple inheritance to avoid ambiguity
- Use virtual inheritance to solve diamond problem
- Interfaces (pure virtual classes) are the safe form of MI
- C++20 concepts can replace some MI use cases

### 🏭 Real-World Usage:
- iostream: `iostream` inherits from both `istream` and `ostream`
- Mixin classes (CRTP-based) are safer alternative
- MI is controversial — most style guides limit its use

### ⚡ Quick Revision:
- MI: ambiguous calls must be qualified with `Base::method()`
- Diamond problem → use virtual inheritance
- Prefer interfaces (abstract classes) for safe MI
- Construction order: left-to-right as listed in inheritance declaration
*/