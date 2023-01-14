#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "creature.h"

#ifndef CHARACTER_H
#define CHARACTER_H

/**
 * @class Character
 * @brief The Character class represents a player or an enemy in the game.
 * Each character has a name and an array of 6 creatures, each of which can be controlled, evolved and attacked.
 * The class also keeps track of the currently focused creature, which is the creature that the player or enemy is currently controlling.
 * The class provides methods for controlling the characters creatures, such as changing the focused creature, evolving a creature,
 * and resetting all creatures' health points. It also has methods for attacking other characters.
 * 
 */
class Character{

    private:
    Creature characterCreatures[6];
    std::string name;
    size_t focusedCreatureIndex;

    /**
     * @brief Initializes the creatures for the character
     * @param index Index of the character, used to determine the properties of the creatures
     */
    void initializeCreatures(int index);

    /**
     * @brief Handles the evolution of a chosen creature
     * @param choice Index of the creature to evolve
     */
    void chooseEvolution(size_t choice);


    public:
    Character();

    /**
     * @brief Constructor that takes in a name and index for the character
     * @param name Name of the character
     * @param index Index of the character, used to determine the properties of the creatures
     */
    Character(std::string name, int index);

    /**
     * @brief Returns the index of the first valid creature for the character to use
     * @param index Index of the character, used to determine which team's creatures to check
     * @return Index of the first valid creature
     */
    int firstValidCreature(int index);

    /**
     * @brief Allows the player to change the creature in focus
     */
    void playerChangeCreature();

    /**
     * @brief Handles the attack of the character's creature in focus on another character's creature in focus
     * @param attacked The character whose creature in focus is being attacked
     */
    void attack(Character &attacked);

    /**
     * @brief Handles the special attack of the character's creature in focus on another character's creature in focus
     * @param attacked The character whose creature in focus is being attacked
     * @return 0 if attack not possible, 1 if successful
     */
    int specialAttack(Character &attacked);

    /**
     * @brief Allows the player to handle the evolution of their creatures
     */
    void evolveHandle();

    /**
     * @brief Function that makes the enemy character choose an action to respond to player's action
     * @param player A reference to the player character object
    */
    void enemyResponse(Character &player);
    
    /**
     * @brief Function that checks if the enemy's currently selected creature is dead and changes it to the next valid one if it is
     * @param index The index of the enemy character in the array of characters 
     */
    void enemyChangeCreatureIfDead(size_t index);
    
    /**
     * @brief Function that resets all of the player's creatures' health points
     */
    void playerResetCreatures();


    Creature& getCreatureInFocus();
    Character setFocusedCreatureIndex(size_t newFocus);
    size_t getFocusedCreatureIndex() const;
    Creature& getCreature(size_t index);

    /**
     * @brief Function that generates a string representation of the character's information
     * @return A string representation of the character's information
     */
    std::string toString();
    
};

#endif