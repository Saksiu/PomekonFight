#include <iostream>
#include <windows.h>
#include <string>

#ifndef CREATURE_H
#define CREATURE_H

enum Force{Water,Earth,Air,Fire,Ice,Steel};

/**
 * SAVE:
 * Water:

Hydro Pump - A powerful water-based attack that can deal heavy damage to the opponent.
Blizzard - A powerful ice attack that can freeze the opponent and deal heavy damage.
Dive - The user submerges and attacks on the second turn, dealing twice the damage taken on the first turn.
Rain Dance - Boosts the power of water-based attacks and causes heavy rain to fall for 5 turns, which can help water-type Pokemon.
Earth:

Earthquake - A powerful ground-based attack that can deal heavy damage to the opponent.
Fissure - A one-hit KO move that instantly defeats the opponent, but has low accuracy.
Rollout - A move that deals damage multiple times. The power increases each time the user uses it in a row.
Stone Edge - A powerful rock-based attack that has high critical hit rate.
Air:

Hurricane - A flying type move, which has high accuracy and can causes confusion to the opponent.
Thunder - A powerful electric type move, which can cause Paralysis on opponent.
Fly - a flying type move, which allows the user to fly to the air, dodging opponent's attack and then attack back.
Aerial Ace - A flying type move, which has high accuracy, and never miss.
Fire:

Fire Blast - A powerful fire-based attack that can deal heavy damage to the opponent.
Flame Thrower - A fire-based attack that has a high chance of burning the opponent.
Lava Plume - A fire-based attack that has a chance of burning all opponents in a double battle or all adjacent opponents in a triple battle.
Inferno - A fire-based attack that has a chance of leaving the opponent badly burned, lowering the opponents special defense.
Ice:

Ice Beam - A powerful ice-based attack that has a chance of freezing the opponent.
Aurora Beam - A powerful ice-based attack that has a chance of lowering the opponent's attack.
Ice Punch - A powerful ice-based attack that has a chance of freezing the opponent.
Glacier Rush - A powerful ice-based attack that deals extra damage to the opponent if they are frozen.
Steel:

Metal Claw - A steel-based attack that has a high chance of raising the user's attack.
Iron Head - A steel-based attack that has a high chance of causing flinching in the opponent.
Steel Beam - A powerful steel-based attack that deals massive damage.
Flash Cannon - A steel-based special attack that has a chance of lowering the opponent's special defense.
 * 
 * 
*/

class Creature{
	
	private:
	static int counter;

	std::string name;
	Force forceType;
	int evolution;
	int strength;
	int lifePoints;
	int maxLifePoints;
	int experience;
	int maxExperience;
	float agility;


	public:
	Creature();

	std::string getName() const;
	int getStrength() const;
	int getLifePoints() const;
	int getMaxLifePoints() const;
	int getExperience() const;
	int getMaxExperience() const;
	float getAgility() const;
	std::string getForceTypeSymbol() const;

	Creature& setEvolution();

	Creature& setName(std::string newName);
	Creature& setAgility(float newAgility);
	Creature& setLifePoints(int newLifePoints);

	void toString();
};
#endif