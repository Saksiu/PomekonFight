#include <iostream>
#include <windows.h>
#include <string>
#include "creature.h"

	Creature::Creature(std::string name,Force forceType,int strength,int lifePoints,double agility){
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
	double Creature::getAgility(){
		return agility;
	}

	std::string Creature::getForceTypeSymbol(){
		switch (forceType)
		{
		case Water: return "W";
			break;
		case Earth: return "E";
			break;
		case Air: return "A";
			break;
		case Fire: return "F";
			break;
		case Ice: return "I";
			break;
		case Steel: return "S";
			break;
		default: return "S";
			break;
		}
	}
	void Creature::setAgility(double newAgility){
		agility=newAgility;
	}
	void Creature::setlifePoints(int newLifePoints){
		lifePoints=newLifePoints;
	}

	std::string Creature::toString(){
		return "name: "+name+" force: "+getForceTypeSymbol()+" strength: "+std::to_string(strength)+
		"\n life points: "+std::to_string(lifePoints)+" agility: "+std::to_string(agility);
	}