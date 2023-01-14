#include <iostream>
#include <windows.h>
#include <string>

#ifndef CREATURE_H
#define CREATURE_H
/**
 * @class Creature
 * @brief Represents a creature in the game
 * This class represents a creature in the game, including its properties, attributes and abilities.
 * The creature has a name, a force type, its ability uses, evolution stage, strength, life points, experience, agility and max experience.
 * The class also includes getters and setters for the creature's properties and methods for evolving, gaining experience, and reseting experience
 * 
 */
enum Force{Water,Earth,Air,Fire,Ice,Steel};

class Creature{
	
	private:
	/**
	 * * @brief counter for the number of creatures
     */
	static int counter;

	std::string name;
	Force forceType;

	int abilityUses;
	int strength;
	int lifePoints;
	int maxLifePoints;
	int experience;
	int maxExperience;
	int agility;

	public:
	Creature();
	/**
	 * @brief Construct a new Creature object with Creature objects scaling up in statistics
	 * 
	 * @param enemyNum number of enemy "in line" to fight with the player
	 */
	Creature(int enemyNum);


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
	/**
 	* @brief Resets the experience of the creature to 0
 	* @return reference to the current creature object
 	*/
	Creature& resetExperience();

	/**
 	* @brief Adds a certain amount of experience to the creature
 	* @param expGained the amount of experience to add
 	* @return reference to the current creature object
 	*/
	Creature& addExperience(int expGained);

	Creature& setAbilityUses(int newUses);
	Creature& setName(std::string newName);
	Creature& setAgility(int newAgility);
	Creature& setLifePoints(int newLifePoints);
	Creature& setMaxLifePoints(int newMaxLifePoints);
	Creature& setStrength(int newStrength);

	/**
	 * @brief Returns a string representation of the creature's information
	 * @return string representation of the creature's information
	 */
	std::string toString();
};
#endif