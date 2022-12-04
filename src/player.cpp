#include <iostream>
#include <string>
#include <windows.h>
#include "player.h"
#include "creature.h"


    Player::Player(){}
    Player::Player(std::string name){
        this->name=name;
    }

    std::string Player::getName(){
        return name;
    }
    std::vector<Creature> Player::getCreatureVector(){
        return playerCreatures;
    }


    void Player::setName(std::string newName){
        name=newName;
    }
    void Player::addCreature(Creature newCreature){
        playerCreatures.push_back(newCreature);
    }
    std::string Player::showCreatures(){
        std::string strToReturn="";
        for(int i=0;i<playerCreatures.size();i++){
            strToReturn+=std::to_string(i+1)+". ";
            strToReturn+=playerCreatures.at(i).toString();
            strToReturn+="\n\n";
        }
        return strToReturn;
    }

    std::string Player::toString(){
        return "name: "+name+"\n Creatures:\n"+showCreatures();
    }