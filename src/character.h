#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "creature.h"

#ifndef CHARACTER_H
#define CHARACTER_H

class Character{

    private:
    std::vector<Creature> characterCreatures;
    std::string name;
    int focusedCreatureIndex;


    public:
    Character();
    Character(std::string name);
    std::string getName();
    std::vector<Creature> getCreatureVector();
    int getFocusedCreatureIndex();
    Creature getCreatureAt(int index);
    Creature getFocusedCreature();

    void putFocusOnCreature(int index);
    void setName(std::string newName);
    void addCreature(Creature newCreature);

    std::string toString();
    std::string showCreatures();

};

#endif