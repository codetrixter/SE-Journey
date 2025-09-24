# TOPICS COVERED

1. [Composition](composition/creature.hpp)

2. [Aggregation](aggregation/dept_teacher.cpp)

3. [Association](association/associativeRelation.cpp)

4. [Dependencies](dependencies/dependency.cpp)

6. [Initializer List](initializerList.cpp)

# What type of relationship (composition, aggregation, association, or dependency) do the following describe?
## a) An Animal class that contains an animal type (enum) and name (string).
## Ans: Composition -- The animal type and name don’t have a use outside of the Animal.

## 1b) A text editor class with a save() function that takes a File object as an argument. The save() function writes the contents of the editor to disk.
## Ans: Dependency -- The text editor class is using the File object for the task of saving to disk.

## 1c) An Adventurer class that can carry various kinds of Items, such as swords, wands, potions, or spellbooks. These Items can be dropped and picked up by other Adventurers.
## Ans: Aggregation -- When the Items are associated with the Adventurer, the Adventurer has-them. A sword being used by an adventurer can’t be used by anybody else at that time. But the Adventurer doesn’t manage the items existences.

## 1d) The Player prays at a Shrine to receive a new power.
## Ans: Dependency -- The player depends on the shrine to receive the power, but does not have any long-term association with it.

## 1e) A Computer class that contains a CPU class. The CPU can be removed from the Computer and tested on its own.
## Ans: Aggregation -- The computer has a CPU, but does not manage its existence.

## 1f) A blacksmith has a specific anvil that he uses to do his work.
## Ans: Association -- The blacksmith uses the anvil, but does not have a whole-part relationship with it.

## Select one: If you can design a class using (composition, aggregation, association, or dependency), then you should.
## Ans: composition