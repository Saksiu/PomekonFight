#include <iostream>
#include <string>
#include <windows.h>
#include "character.h"
#include "creature.h"


    Character::Character(){}
    Character::Character(std::string name, int index){
        this->name=name;
        this->focusedCreatureIndex=0;
        initializeCreatures(index);
    }
    void Character::initializeCreatures(int index){
        using std::cin,std::cout;
        const size_t poolSize=10;
        std::vector <Creature> playerPool;
        if(index==0){

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
        else{   //Enemy random creature generation
            for(size_t i=0;i<4;i++)
                characterCreatures[i]=Creature();
        }
    }

   /**
     * RETURNS:
     *  1  IF creature currently in focus is ALIVE (do nothing)
     *  0  IF creature currently in focus is DEAD and it wasn't last (choose for player, pick next for enemy if valid)
     * -1  IF last enemy creature is DEAD (round lost for player or enemy)
    */

    int Character::chooseNextValidCreature(int index){
        if(this->getCreatureInFocus().getLifePoints()>0) //in focus is alive all good
            return 1;

        //in focus is dead
        bool hasNext=false;
        size_t iterator=4;

        if(index==0)
            iterator=6;

        for(size_t i=0;i<iterator;i++)
            if(this->characterCreatures[i].getLifePoints()>0)
                hasNext=true;

        if(hasNext){    //there is replacement
            if(index>0)     //enemy
                this->setFocusedCreatureIndex((this->getFocusedCreatureIndex()+1));
            return 0;
            
        }
        //there is no replacement
        return -1;
    }

    void Character::playerChangeCreature(){
        bool badInput=true;

        while(badInput){
            std::cout<<"\n\n\n\n\n";    //evil again
            std::cout<<"Choose creature: \n";
            this->toString();

            int choice;
            std::cin>>choice;
            if(choice>=1&&choice<=6&&this->getCreature(choice-1).getLifePoints()>0){
                focusedCreatureIndex=choice-1;
                badInput=false;
            }
            else{
                std::cout<<"\nWrong choice!\n";
            }
        }
    }

    Creature& Character::getCreatureInFocus(){
        return this->getCreature(this->getFocusedCreatureIndex());
    }

    void Character::attack(Character &attacked){
        attacked.characterCreatures[attacked.getFocusedCreatureIndex()].setLifePoints(

            attacked.characterCreatures[attacked.getFocusedCreatureIndex()].getLifePoints()
            -
            this->characterCreatures[this->getFocusedCreatureIndex()].getStrength());
    }

    void Character::specialAttack(Character &Attacked){
        
    }

    void Character::heal(){
        //float healingFactor=0.2;
        //this->getCreatureInFocus().setLifePoints(
        //this->getCreatureInFocus().getLifePoints()+
        //this->getCreatureInFocus().getMaxLifePoints()*
        //healingFactor);

        this->getCreatureInFocus().setLifePoints(this->getCreatureInFocus().getLifePoints()+25);
        //...
    }

    void Character::evolve(){

    }
/**
 *  ENEMY STATE FUNCTION
 *  BASICLOOP:
 *  1. IF enemy creature KILLED change to next one
 *  1. IF creature on 20% MAX health OR unable to withstand next attack/special attack from PLAYER FOCUSED  creature, HEAL
 *  2. ELSE IF ABLE to kill player creature using attack/special attack CHOOSE EASIEST OPTION to kill
 *  3. ELSE deal most damage possible in turn
 * 
 * 
 * IDEAS: make enum "state" and "personality" dictating enemy responses
*/
    void Character::enemyResponse(Character &player){

        if(this->getCreatureInFocus().getLifePoints()<this->getCreatureInFocus().getMaxLifePoints()/5
            ||this->getCreatureInFocus().getLifePoints()<player.getCreatureInFocus().getStrength()){
            heal();
        }
        else{
            this->attack(player);
        }
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