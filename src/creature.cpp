#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include "creature.h"


	
	Creature::Creature(){}
	Creature::Creature(int enemyNum){
		this->name=std::to_string(counter);
		float multiplier;
		switch(enemyNum){
			case 1:
				multiplier=1.0;
				break;
			case 2: case 3:
				multiplier=1.2;
				break;
			case 4:
				multiplier=1.4;
				break;
			default:
				multiplier=1.0;
				break;
		}

		int forcePointer=rand()%6+1;
		switch (forcePointer){
		case 1: this->forceType=Water;
			break;
		case 2: this->forceType=Earth;
			break;
		case 3: this->forceType=Air;
			break;
		case 4: this->forceType=Fire;
			break;
		case 5: this->forceType=Ice;
			break;
		case 6: this->forceType=Steel;
			break;
		default: this->forceType=Steel;
			break;
		}
		this->abilityUses=2;
		this->strength=(rand()%20+20)*multiplier;
		this->maxLifePoints=(rand()%20+4)*10*multiplier;
		this->lifePoints=maxLifePoints;
		this->agility=rand()%20+5*multiplier;
		this->experience=0;
		this->maxExperience=1000;
		counter++;
	}

	std::string Creature::getName() const{
		return name;
	}
	int Creature::getStrength() const{
		return strength;
	}
	int Creature::getLifePoints() const{
		return lifePoints;
	}
	int Creature::getMaxLifePoints() const{
		return maxLifePoints;
	}
	int Creature::getAbilityUses() const{
		return abilityUses;
	}
	int Creature::getExperience() const{
		return experience;
	}
	int Creature::getMaxExperience() const{
		return maxExperience;
	}
	int Creature::getAgility() const{
		return agility;
	}

	Force Creature::getForceType() const{
		return forceType;
	}

	std::string Creature::getForceTypeSymbol() const{
		switch (forceType)
		{
		case Water: return "Water";
			break;
		case Earth: return "Earth ";
			break;
		case Air: return "Air  ";
			break;
		case Fire: return "Fire ";
			break;
		case Ice: return "Ice  ";
			break;
		case Steel: return "Steel";
			break;
		default: return "Steel";
			break;
		}
	}

	Creature& Creature::resetExperience(){
		this->experience-=this->maxExperience;
		this->maxExperience+=this->maxExperience/2;
		return *this;
	}

	Creature& Creature::setName(std::string newName){
		std::cout<<"\nNAME: changing "<<name<<" to "<<newName<<"\n";
		this->name=newName;
		return *this;
	}

	Creature& Creature::addExperience(int expGained){
		std::cout<<"\nEXP: gained "<<expGained<<"\n";
		this->experience+=expGained;
		return *this;
	}

	Creature& Creature::setAbilityUses(int newUses){
		std::cout<<"\nAbility: "<<newUses<<" uses left\n";
		this->abilityUses=newUses;
		return *this;
	}

	Creature& Creature::setAgility(int newAgility){
		std::cout<<"\nAGL: changing "<<agility<<" to "<<newAgility<<"\n";
		this->agility=newAgility;
		return *this;
	}
	
	Creature& Creature::setLifePoints(int newLifePoints){
		std::cout<<"\nHP: changing "<<lifePoints<<" to "<<newLifePoints<<"\n";
		this->lifePoints=newLifePoints;
		return *this;
	}
	Creature& Creature::setMaxLifePoints(int newMaxLifePoints){
		std::cout<<"\nMAX HP: changing "<<maxLifePoints<<" to "<<newMaxLifePoints<<"\n";
		this->maxLifePoints=newMaxLifePoints;
		return *this;
	}

	Creature& Creature::setStrength(int newStrength){
		std::cout<<"\nSTR: changing "<<strength<<" to "<<newStrength<<"\n";
		this->strength=newStrength;
		return *this;
	}
	
	std::string Creature::toString(){
		using std::to_string;
		return "|Creature_"+name+" | FRC: "+getForceTypeSymbol()+
		" | HP: "+to_string(lifePoints)+" | STR: "+to_string(strength)+" | AGL: "+
		to_string(agility)+" | EXP: "+to_string(experience)+"/"+to_string(maxExperience);
	}