/**
 * @file creature.hpp
 * @author Abhishek
 * @brief Here we discuss about the object composition:
 * To qualify as a composition, an object and a part must have the following relationship:

    1- The part (member) is part of the object (class)
    2- The part (member) can only belong to one object (class) at a time
    3- The part (member) has its existence managed by the object (class)
    4- The part (member) does not know about the existence of the object (class)

 * 1- Here creature object is composed of point2D instance.
 * 2- Some benefits of composition:
 *  a. Lowering the complexity of the design since the main class is composed of several different classes which are created separately.
 *  b. Increases the resusability of the indivisual classes i.e: point2D class can be used for other things as well like finding the pixel location.
 * 
 * TIP: A good rule of thumb is that each class should be built to accomplish a single task. That task should either be the storage and manipulation 
 * of some kind of data (e.g. Point2D, std::string), OR the coordination of its members (e.g. Creature). Ideally not both.
 * @version 0.1
 * @date 2022-08-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include "point2D.hpp"

class Creature
{
private:
    std::string m_name;
    Point2D m_location;

public:
    Creature(const std::string& name, const Point2D& location)
        : m_name{ name }, m_location{ location }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Creature& creature)
    {
        out << creature.m_name << " is at " << creature.m_location;
        return out;
    }

    void moveTo(int x, int y)
    {
        m_location.setPoint(x, y);
    }
};
#endif