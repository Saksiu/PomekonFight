#include <iostream>
#include <string>
#include <windows.h>
#include "character.h"
#include "creature.h"


    Character::Character(){}
    Character::Character(std::string name, size_t index){
        this->name=name;
        this->focusedCreatureIndex=0;
        initializeCreatures(index);
    }

    void Character::initializeCreatures(size_t index){
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
                    cout<<playerPool[j].toString();
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
        size_t choice;

        while(badInput){
            std::cout<<this->toString();

            std::cin.ignore(1000,'\n');
            std::cin>>choice;
            if(choice>=1&&choice<=6&&this->getCreature(choice-1).getLifePoints()>0){
                badInput=false;
                this->setFocusedCreatureIndex(choice-1);
            }
            else{
                std::cout<<"\nWrong choice!\n";
            }
        }
    }

    Creature& Character::getCreatureInFocus(){
        return this->getCreature(this->getFocusedCreatureIndex());
    }

    void Character::chooseEvolution(size_t creatureChoice){
        int attributeChoice;
        bool badInput=true;
        int oldLifePoints=this->getCreature(creatureChoice).getMaxLifePoints();
        int oldStrength=this->getCreature(creatureChoice).getStrength();
        int oldAgility=this->getCreature(creatureChoice).getAgility();

        while(badInput){

            std::cout<<"\n\n\n"<<this->getCreature(creatureChoice).toString();

            std::cout<<"\nChoose attributes to upgrade:\n";

            std::cout<<"\n1.LV + STR: "<<oldLifePoints<<" + "<<oldStrength;

            std::cout<<"\n2.LV + AGL: "<<oldLifePoints<<" + "<<oldAgility;

            std::cout<<"\n3.STR + AGL: "<<oldStrength<<" + "<<oldAgility<<std::endl;

            std::cin.ignore(1000,'\n');
            std::cin>>attributeChoice;

            if(attributeChoice>=1&&attributeChoice<=3)
                badInput=false;
            else
                std::cout<<"\nWrong choice!\n";
        }

        float multiplier=(rand()%20+20)/100.0;

        if(attributeChoice!=3)  //life
            this->getCreature(creatureChoice).setLifePoints(
                this->getCreature(creatureChoice).getMaxLifePoints()*(1+multiplier));

        if(attributeChoice!=1)  //agility
            this->getCreature(creatureChoice).setAgility(
                this->getCreature(creatureChoice).getAgility()*(1+multiplier));

        if(attributeChoice!=2)  //strength
            this->getCreature(creatureChoice).setStrength(
                this->getCreature(creatureChoice).getStrength()*(1+multiplier));


        this->getCreature(creatureChoice).resetExperience();
        std::cout<<std::endl<<this->getCreature(creatureChoice).toString();
    }

    int Character::attack(Character &attacked){
        int chance=rand()%99+1;
        if(attacked.getCreatureInFocus().getAgility()>=chance){
            this->getCreatureInFocus().addExperience(this->getCreatureInFocus().getAgility()*20);
            return -1;
        }
        else{
            attacked.getCreatureInFocus().setLifePoints(attacked.getCreatureInFocus().getLifePoints()-this->getCreatureInFocus().getStrength());

            this->getCreatureInFocus().addExperience(this->getCreatureInFocus().getStrength()*2);
            return 1;
        }

        
    }

    void Character::specialAttack(Character &attacked){
        
    }

    void Character::evolveHandle(){
        bool toEvolve=false,badInput=true;
        size_t choice;
        std::cout<<"Choose creature to evolve!\n";
        for(size_t i=0;i<6;i++)
            if(this->getCreature(i).getExperience()>=this->getCreature(i).getMaxExperience())
                toEvolve=true;
        
        if(toEvolve){

            while(badInput){
                std::cout<<this->toString();

                std::cin.ignore(1000,'\n');
                std::cin>>choice;
                choice-=1;
                if(choice>=0&&choice<=5&&this->getCreature(choice).getExperience()>=this->getCreature(choice).getMaxExperience()){
                    badInput=false;
                    this->chooseEvolution(choice);
                }
                else{
                   std::cout<<"\nWrong choice!\n";
                }
            }

        }
        else{
            std::cout<<"You don't have any viable creatures to evolve!";
        }
            
    }
/**
 *  ENEMY STATE FUNCTION
 *  BASICLOOP:
 *  1. IF ABLE to kill player creature using attack/special attack CHOOSE EASIEST OPTION to kill
 *  3. ELSE deal most damage possible in turn
 * 
 * IDEAS: make enum "state" and "personality" dictating enemy responses
*/
    void Character::enemyResponse(Character &player){

        if(false){      //1.

        }
        else{           //2.
            this->attack(player);
        }
    }
    void Character::playerResetCreatures(){
        for(size_t i=0;i<6;i++)
            this->getCreature(i).setLifePoints(this->getCreature(i).getMaxLifePoints());
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

    std::string Character::toString(){
        std::string string="";
        size_t iterator=4;
        if(name=="Player")
            iterator=6;
        string+="\nname: "+name+"\nCreatures:\n";
        for(size_t i=0;i<iterator;i++){
            string+=std::to_string(i+1)+". ";
            string+=characterCreatures[i].toString();
            string+="\n\n";
        }
        return string;
    }