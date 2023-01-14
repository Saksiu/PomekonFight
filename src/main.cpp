#include <iostream>
#include <string>
#include "creature.h"
#include "character.h"

int Creature::counter=0;
Character characters[5];

/**
 * @brief Clears the console screen.
 * This function is used to clear the console screen. It prints a certain number of new lines to the console
 */
void clearScreen(){
	for(size_t i=0;i<10;i++)
		std::cout<<std::endl;
	std::cin.ignore(1000,'\n');
}
/**
 * @brief A function to save the game state. TBD
 * 
 */
void save(){


	endGame(0);
}
/**
 * @brief Ends the game and displays the appropriate message.
 * @param state The state of the game:
 * 0: player saved and exited, game not finished
 * 1: player lost, all creatures dead
 * 2: player won, all enemies defeated
 */

void endGame(int state){
	clearScreen();
	switch(state){
		case 0:
			std::cout<<"Game saved! See you soon!";
			break;
		case 1:
			std::cout<<"Game over! You lost!";
			break;
		case 2:
			std::cout<<"Good job! You won the game!\n You are the master!!!";
			break;
		default:
			std::cout<<"Error: this shouldn't appear";
			break;
	}
	std::cout<<"\nThank you for playing.\n";
	std::cout<<"\nGame made by Maks Spisjak s25303\n";
	exit(0);
}
/**
 * @brief A function to display a short description of the game.
 */
static void showHelp(){
	using std::cout;
	cout<<"\n\n|HELP|:\n\n";
	cout<<"You, the greatest poMeKon master of all time, are tasked with picking your team of 6 creatures.\n";
	cout<<"The objective is to use those creatures to dominate the battlefield, by using abilites, attacks and evolving your creatures.\n";
	cout<<"The game consists of 4 rounds, each with an ever-stronger enemy, each having 4 creatures.\n\n";
	cout<<"Between rounds all of your creatures are fully healed, and you can choose to evolve some of them, or start the next round.\n";
	cout<<"If all of your creatures health goes down to/below 0, they fall unconsious and can't be used until next round.\n\n";
	cout<<"Every creature has 3 main statistics:\n1.HP-Health Points\n2.STR-Strength\n3.AGL-Agility\n";
	cout<<"Each creature contains a force type.\nThese force types determine how effective their abilities are.\n";
	cout<<"If a creature has enough EXP, you may evolve it, by choosing which 2 of the base attributes to upgrade.\n\n";
	}

/**
 * @brief 
 * Starts round, takes round number as num
 * A round is divided by turns, first the player can choose the action, and then the enemy responds to it
 * A round ends if either all of player's, or the enemy's creatures are dead, 
 * which the chooseNextValidCreature() func checks
 * 
 * At the end of the round all of the player's creatures's health points reset,
 * and the player returns to the round menu
 * 
 * @param num The round number.
*/
void startRound(size_t num){
	using std::cout,std::cin;
	int choice,turnCounter=0;
	bool badInput,canRespond;

	cout<<"\nEnemy creatures:\n";
	cout<<characters[num].toString();

	cout<<"\nEnemy starting creature:\n";
	cout<<characters[num].getCreatureInFocus().toString();

	cout<<"\n\nChoose starting creature for the round!\n";
	characters[0].playerChangeCreature();

	while(characters[num].firstValidCreature(num)>=0){
		turnCounter++;

		if(characters[0].firstValidCreature(0)<0){
			endGame(1);
		}
		else if(characters[0].getCreatureInFocus().getLifePoints()<=0){
			cout<<"Your creature died!\n Choose next one to fight!";
			characters[0].playerChangeCreature();
		}
		characters[num].enemyChangeCreatureIfDead(num);

		clearScreen();
		cout<<"Round No. "<<num<<" Turn No. "<<turnCounter;
		cout<<"\n-----------------------";
		cout<<"\nYour creature:\n";
		cout<<characters[0].getCreatureInFocus().toString();

		cout<<"\n\nEnemy creature:\n";
		cout<<characters[num].getCreatureInFocus().toString();

		cout<<"\n\nChoose action: \n";
		cout<<"1. Attack\n2. Special attack\n3. Change creature\n4. Help\n";
		badInput=true;
		canRespond=true;

		while(badInput){
            cin>>choice;
            if(choice>=1&&choice<=4)
                badInput=false;
            else
               cout<<"\nWrong choice!\n";
		}

		switch (choice){
		case 1:
			cout<<"Your";
			characters[0].attack(characters[num]);
			break;
		case 2:
			cout<<"Your";
			canRespond=characters[0].specialAttack(characters[num])==1;
			break;
		case 3:
			cout<<"Choose creature!\n";
			characters[0].playerChangeCreature();
			break;
		case 4:
			showHelp();
			canRespond=false;
			turnCounter--;
			break;
		}
		
		if(canRespond){
			cout<<"Enemy ";
			characters[num].enemyResponse(characters[0]);
		}
	}
	characters[0].playerResetCreatures();
}
/**
 * @brief
 * The main game loop that handles the game flow and manages the different game states.
 * The player can choose between starting the next round, evolving their creatures, saving and quitting the game, or getting help.
 * The player will go through 4 rounds, and at the end of each round the player will be presented with the above options.
 * The game ends when the player completes all 4 rounds.
 */
void gameLoop(){
	using std::cout,std::cin;

	char choice;
	size_t roundNum=0;

	while(roundNum<4){
		clearScreen();

		cout<<"\n";
		cout<<characters[0].toString();
		cout<<"\n\nChoose action: \n";
		cout<<"1. Start next round\n2. Evolve creature\n3. Save and Quit\n4. Help\n";
		cin>>choice;

		switch (choice){
		case '1':
			roundNum++;
			startRound(roundNum);
			break;
		case '2':
			characters[0].evolveHandle();
			break;
		case '3':
			save();
			exit(0);
			break;
		case '4':
			showHelp();
			break;
		default:
			cout<<"\nWrong choice, try again: ";
			cin.clear();
		break;
		}
	}
}

/**
 * @brief
 * Initializes the characters in the game, creates a player character and 4 enemy characters.
 * The player character is assigned the name "Player" and an ID of 0, 
 * while the enemy characters are assigned the name "Enemy" plus their ID (1-4)
 * 
 */
void initializeCharacters(){
	characters[0]=Character("Player",0);
	for(int i=1;i<5;i++)
		characters[i]=Character("Enemy"+std::to_string(i),i);
}

void startGame(){
	srand(time(NULL));
	showHelp();
	std::cout<<"Let's begin!\n";
	initializeCharacters();

	gameLoop();
	endGame(2);
}


int main()
{
	startGame();
	system("pause");
}
