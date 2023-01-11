#include <iostream>
#include <windows.h>
#include <string>
#include "creature.h"



	Creature::Creature(){
		this->name=std::to_string(counter);
		this->evolution=1;

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
		this->strength=rand()%20+20;
		
		this->maxLifePoints=rand()%200+40;
		this->lifePoints=maxLifePoints;
		this->agility=rand()%99+1;
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
	int Creature::getExperience() const{
		return experience;
	}
	int Creature::getMaxExperience() const{
		return maxExperience;
	}
	float Creature::getAgility() const{
		return agility;
	}

	std::string Creature::getForceTypeSymbol() const{
		switch (forceType)
		{
		case Water: return "Water";
			break;
		case Earth: return "Earth";
			break;
		case Air: return "Air  ";
			break;
		case Fire: return "Fire";
			break;
		case Ice: return "Ice  ";
			break;
		case Steel: return "Steel";
			break;
		default: return "Steel";
			break;
		}
	}

	Creature& Creature::setEvolution(){
		this->evolution++;
		return *this;
	}

	Creature& Creature::setName(std::string newName){
		std::cout<<"\nchanging "<<name<<" to "<<newName<<"\n";
		this->name=newName;
		return *this;
	}

	Creature& Creature::setAgility(float newAgility){
		std::cout<<"\nchanging "<<agility<<" to "<<newAgility<<"\n";
		this->agility=newAgility;
		return *this;
	}
	
	Creature& Creature::setLifePoints(int newLifePoints){
		std::cout<<"\nchanging "<<lifePoints<<" to "<<newLifePoints<<"\n";
		this->lifePoints=newLifePoints;
		return *this;
	}
	
	void Creature::toString(){
		using std::cout,std::to_string;
		cout<<"NAME: Creature_"+name+"  FRC: "+getForceTypeSymbol()+"  STR: "+to_string(strength)+
		"  LP: "+to_string(lifePoints)+"  AGL: "+to_string(agility)+"  EXP: "+to_string(experience)+"/"+to_string(maxExperience);
	}