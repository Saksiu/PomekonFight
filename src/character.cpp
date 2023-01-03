#include <iostream>
#include <string>
#include <windows.h>
#include "character.h"
#include "creature.h"


    Character::Character(){}
    Character::Character(std::string name){
        this->name=name;
        this->focusedCreatureIndex=0;
        initializeCreatures();
    }
    void Character::initializeCreatures(){
        using std::cin,std::cout;
        const size_t poolSize=10;
        std::vector <Creature> playerPool;
        if(name=="Player"){

            for(size_t i=0;i<poolSize;i++){
                playerPool.push_back(Creature());
            }

            int choice;
	        for(int i=0;i<6;i++){
                cout<<"\nChoose your Creature ("<<i+1<<" out of 6):\n";

                for(int j=0;j<playerPool.size();j++){
                    cout<<"| "<<j+1<<". "; 
                    playerPool[j].toString();
                    cout<<"\n|-------------------------------------------------------------------------------------\n";
                }
                  
                cout<<"\n";

                cin>>choice;
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";   //evil

                if(choice<1||choice>playerPool.size()||cin.bad()){
                    cout<<"\nWrong choice, try again";
                    cin.clear();
                    cin.ignore(1000,'\n');
                    i--;
                }
                else{
                    characterCreatures[i]=playerPool[choice-1];
                    playerPool.erase(playerPool.begin()+choice-1);
                }
	        }
        }
        else{   //Happens only if name is not "Player"
            for(size_t i=0;i<4;i++)
                characterCreatures[i]=Creature();
        }
    }

    int Character::enemyDecideCreature(){
        size_t iterator=4;
        if(name=="Player")
            iterator=6;
        for(size_t i=0;i<iterator;i++)
            if(characterCreatures[i].getlifePoints()>0)
                return i;
        std::cout<<"we are done!";
        iterator=0-1;
        return iterator;
    }
    void Character::playerChangeCreature(){
        bool badInput=true;
        while(badInput){
            std::cout<<"\n\n\n\n\n";    //evil again
            std::cout<<"Choose creature: \n";
            this->toString();
            int choice;
            std::cin>>choice;
            if(choice>=1&&choice<=6){
                focusedCreatureIndex=choice-1;
                badInput=false;
            }
            else{
                std::cout<<"\nWrong choice!\n";
            }
        }
    }

    void Character::attack(Character &attacked){
        attacked.characterCreatures[attacked.getFocusedCreatureIndex()].setlifePoints(

            attacked.characterCreatures[attacked.getFocusedCreatureIndex()].getlifePoints()
            -
            this->characterCreatures[this->getFocusedCreatureIndex()].getStrength());
    }


    Character Character::setFocusedCreatureIndex(size_t newFocus){
        this->focusedCreatureIndex=newFocus;
        return *this;
    }
    size_t Character::getFocusedCreatureIndex() const{
        return focusedCreatureIndex;
    }

    Creature& Character::getCreature(size_t index){
        return characterCreatures[index];
    }

    void Character::toString(){
        using std::cout;
        size_t iterator=4;
        if(name=="Player")
            iterator=6;
        cout<<"\nname: "+name+"\nCreatures:\n";
        for(size_t i=0;i<iterator;i++){
            cout<<std::to_string(i+1)+". ";
            characterCreatures[i].toString();
            cout<<"\n\n";
        }
    }