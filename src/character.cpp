#include <iostream>
#include <string>
#include <windows.h>
#include "character.h"
#include "creature.h"


    Character::Character(){
        this->focusedCreatureIndex=0;
    }
    Character::Character(std::string name){
        this->name=name;
        this->focusedCreatureIndex=0;
    }

    std::string Character::getName(){
        return name;
    }
    std::vector<Creature> Character::getCreatureVector(){
        return characterCreatures;
    }
    int Character::getFocusedCreatureIndex(){
        return focusedCreatureIndex;
    }
    Creature Character::getCreatureAt(int index){
        return characterCreatures.at(index);
    }
    Creature Character::getFocusedCreature(){
        return characterCreatures.at(focusedCreatureIndex);
    }


    void Character::setName(std::string newName){
        name=newName;
    }
    void Character::addCreature(Creature newCreature){
        characterCreatures.push_back(newCreature);
    }
    void Character::putFocusOnCreature(int index){
        focusedCreatureIndex=index;
    }

    std::string Character::showCreatures(){
        std::string strToReturn="";
        for(int i=0;i<characterCreatures.size();i++){
            strToReturn+=std::to_string(i+1)+". ";
            strToReturn+=characterCreatures.at(i).toString();
            strToReturn+="\n\n";
        }
        return strToReturn;
    }

    std::string Character::toString(){
        return "name: "+name+"\n Creatures:\n"+showCreatures();
    }