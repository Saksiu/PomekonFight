#include <iostream>
#include <windows.h>
#include <string>
#include "creature.h"



	Creature::Creature(){
		this->name=std::to_string(counter);
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
		this->lifePoints=rand()%70+80;
		this->agility=rand()%10+1-((float)(rand()%10+1)/10.0);
		counter++;
	}

	std::string Creature::getName() const{
		return name;
	}
	int Creature::getStrength() const{
		return strength;
	}
	int Creature::getlifePoints() const{
		return lifePoints;
	}
	int Creature::getExperience() const{
		return experience;
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
	Creature& Creature::setAgility(float newAgility){
		agility=newAgility;
		return *this;
	}
	
	Creature& Creature::setlifePoints(int newLifePoints){
		std::cout<<"\nchanging "<<lifePoints<<" to "<<newLifePoints<<"\n";
		this->lifePoints=newLifePoints;
		return *this;
	}
	
	void Creature::toString(){
		using std::cout;
		cout<<"name: Creature_"+name+"  force: "+getForceTypeSymbol()+"  strength: "+std::to_string(strength)+
		"  life points: "+std::to_string(lifePoints)+"  agility: "+std::to_string(agility);
	}