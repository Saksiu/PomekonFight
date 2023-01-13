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

	int abilityUses;
	int evolution;
	int strength;
	int lifePoints;
	int maxLifePoints;
	int experience;
	int maxExperience;
	int agility;



	public:
	Creature();

	//int attack(Creature &attacked);
	//void specialAttack(Creature &attacked);

	std::string getName() const;
	int getStrength() const;
	int getLifePoints() const;
	int getMaxLifePoints() const;
	int getAbilityUses() const;
	int getExperience() const;
	int getMaxExperience() const;
	int getAgility() const;
	Force getForceType() const;
	std::string getForceTypeSymbol() const;

	Creature& resetExperience();

	Creature& addExperience(int expGained);
	Creature& setAbilityUses(int newUses);
	Creature& setName(std::string newName);
	Creature& setAgility(int newAgility);
	Creature& setLifePoints(int newLifePoints);
	Creature& setMaxLifePoints(int newMaxLifePoints);
	Creature& setStrength(int newStrength);

	std::string toString();
};
#endif