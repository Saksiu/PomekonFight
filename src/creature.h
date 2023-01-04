#include <iostream>
#include <windows.h>
#include <string>

#ifndef CREATURE_H
#define CREATURE_H

enum Force{Water,Earth,Air,Fire,Ice,Steel};

class Creature{
	
	private:
	static int counter;
	std::string name;
	Force forceType;
	int strength;
	int lifePoints;
	int maxLifePoints;
	int experience;
	float agility;


	public:
	Creature();

	std::string getName() const;
	int getStrength() const;
	int getLifePoints() const;
	int getMaxLifePoints() const;
	int getExperience() const;
	float getAgility() const;
	std::string getForceTypeSymbol() const;

	Creature& setAgility(float newAgility);
	Creature& setLifePoints(int newLifePoints);

	void toString();
};
#endif