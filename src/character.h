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
    void initializeCreatures(int index);
    Creature& getCreatureInFocus();


    public:
    Character();
    Character(std::string name, int index);
    int chooseNextValidCreature(int index);
    void playerChangeCreature();
                                            //TODO: FINISH
    void attack(Character &attacked);
    void specialAttack(Character &attacked);

    void evolve();
    void enemyResponse(Character &player);
    void playerResetCreatures();



    Character setFocusedCreatureIndex(size_t newFocus);
    size_t getFocusedCreatureIndex() const;
    Creature& getCreature(size_t index);
    void toString();
    
};

#endif