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

    void initializeCreatures(size_t index);
    void chooseEvolution(size_t choice);


    public:
    Character();
    Character(std::string name, size_t index);

    //int chooseNextValidCreature(int index);
    int firstValidCreature(size_t index);
    void playerChangeCreature();
                                            //TODO: FINISH
    void attack(Character &attacked);
    int specialAttack(Character &attacked);

    void evolveHandle();
    void enemyResponse(Character &player);
    void enemyChangeCreatureIfDead(size_t index);
    void playerResetCreatures();


    Creature& getCreatureInFocus();
    Character setFocusedCreatureIndex(size_t newFocus);
    size_t getFocusedCreatureIndex() const;
    Creature& getCreature(size_t index);
    std::string toString();
    
};

#endif