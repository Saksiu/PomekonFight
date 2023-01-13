#include <iostream>
#include <windows.h>
#include <string>
#include "ability.h"

#ifndef CREATURE_H
#define CREATURE_H



class Creature{
	
	private:
	static int counter;

	std::string name;
	Force forceType;
	size_t abilityIndex;
	int evolution;
	int strength;
	int lifePoints;
	int maxLifePoints;
	int experience;
	int maxExperience;
	int agility;



	public:
	static std::vector<Ability*> abilites;

	Creature();


	int attack(Creature &attacked);
	void specialAttack(Creature &attacked);

	std::string getName() const;
	int getStrength() const;
	int getLifePoints() const;
	int getMaxLifePoints() const;
	int getExperience() const;
	int getMaxExperience() const;
	int getAgility() const;
	std::string getForceTypeSymbol() const;

	Creature& resetExperience();

	Creature& addExperience(int expGained);
	Creature& setName(std::string newName);
	Creature& setAgility(int newAgility);
	Creature& setLifePoints(int newLifePoints);
	Creature& setMaxLifePoints(int newMaxLifePoints);
	Creature& setStrength(int newStrength);

	std::string toString();
};
#endif