#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "creature.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player{

    private:
    std::vector<Creature> playerCreatures;
    std::string name;


    public:
    Player();
    Player(std::string name);
    std::string getName();
    std::vector<Creature> getCreatureVector();

    void setName(std::string newName);
    void addCreature(Creature newCreature);

    std::string toString();
    std::string showCreatures();

};

#endif