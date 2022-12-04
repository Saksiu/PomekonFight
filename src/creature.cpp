#include <iostream>
#include <windows.h>
#include <string>
#include "creature.h"

	Creature::Creature(std::string name,Force forceType,int strength,int lifePoints,float agility){
		this->name=name;
		this->forceType=forceType;
		this->strength=strength;
		this->lifePoints=lifePoints;
		this->agility=agility;
		this->experience=0;
	}

	std::string Creature::getName(){
		return name;
	}
	int Creature::getStrength(){
		return strength;
	}
	int Creature::getlifePoints(){
		return lifePoints;
	}
	int Creature::getExperience(){
		return experience;
	}
	float Creature::getAgility(){
		return agility;
	}

	std::string Creature::getForceTypeSymbol(){
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
	void Creature::setAgility(float newAgility){
		agility=newAgility;
	}
	void Creature::setlifePoints(int newLifePoints){
		lifePoints=newLifePoints;
	}

	std::string Creature::toString(){
		return "name: "+name+"  force: "+getForceTypeSymbol()+"  strength: "+std::to_string(strength)+
		"  life points: "+std::to_string(lifePoints)+"  agility: "+std::to_string(agility);
	}