#include <string>
#include <iostream>
#include "creature.hpp"
#include "point2D.hpp"

int main()
{
    std::cout << "Enter a name for your creature: ";
    std::string name;
    std::cin >> name;
    Creature creature{ name, { 4, 7 } };

    while (true)
    {
        // print the creature's name and location
        std::cout << creature << '\n';

        std::cout << "Enter new X location for creature (-1 to quit): ";
        int x{ 0 };
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Enter new Y location for creature (-1 to quit): ";
        int y{ 0 };
        std::cin >> y;
        if (y == -1)
            break;

        creature.moveTo(x, y);
    }

    return 0;
}

/*
## 📝 CONCEPT ANALYSIS

### 🔑 Core Concepts Demonstrated:
| # | Concept | Where Used |
|---|---------|-----------|
| 1 | **Composition** | Creature HAS-A Point2D (owns it, manages its lifetime) |
| 2 | **Encapsulation** | Point2D manages x,y; Creature manages name+position |
| 3 | **Object lifetime** | Point2D dies with Creature (part-of relationship) |

### 🏭 Real-World Usage:
- Game entities composed of Transform, Mesh, Physics components
- GUI: Window composed of TitleBar, MenuBar, ContentArea

### ⚡ Quick Revision:
- Composition = "part-of" — part cannot exist without whole
- Part's lifetime managed entirely by the whole
- Prefer composition over inheritance for HAS-A relationships
*/