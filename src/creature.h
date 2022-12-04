#include <iostream>
#include <windows.h>
#include <string>

#ifndef CREATURE_H
#define CREATURE_H

enum Force{Water,Earth,Air,Fire,Ice,Steel};

class Creature{

	private:
	std::string name;
	Force forceType;
	int strength;
	int lifePoints;
	int experience;
	float agility;
	

	public:
	Creature(std::string name,Force forceType,int strength,int lifePoints,float agility);

	std::string getName();
	int getStrength();
	int getlifePoints();
	int getExperience();
	float getAgility();

	std::string getForceTypeSymbol();
	void setAgility(float newAgility);
	void setlifePoints(int newLifePoints);

	std::string toString();
};
#endif