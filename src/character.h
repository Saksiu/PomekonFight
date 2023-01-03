#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "creature.h"

#ifndef CHARACTER_H
#define CHARACTER_H

class Character{

    private:
    Creature characterCreatures[6];
    std::string name;
    size_t focusedCreatureIndex;
    void initializeCreatures();


    public:
    Character();
    Character(std::string name);
    int enemyDecideCreature();
    void playerChangeCreature();
                                            //TODO: FINISH
    void attack(Character &attacked);
    void specialAttack(Character &Attacked);
    void heal();
    void evolve();
    



    Character setFocusedCreatureIndex(size_t newFocus);
    size_t getFocusedCreatureIndex() const;
    Creature& getCreature(size_t index);
    void toString();
    
};

#endif