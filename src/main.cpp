#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <string>
#include <limits>
#include "creature.h"
#include "character.h"

/**
 * 	ISSUES:
 * 	Ability class cant influence any creature object because of potential reference circulation
 *  Static abilities list in creature class,
 *  initialized and abilities "created" in main class before initializing characters
 * 	called in the creature class directly, just as attack function
 * 	POTENTIALFIX:
 * 	make abilities reference directly in the character class, as well as the static list to all abilities,
 * 	call abilities within the character class, potentially(maybe) avoiding self-reference conflict
 * 
 * 	TODO:	
 * 	
 * 	1. MAIN GAMEPLAY LOGIC - IN PROGRESS
 * 	2. UI FOR FIGHTS
 *  3. PLAYERSTATE SAVE/LOAD SYSTEM
 * 	4. DIFFICULTY
 *	5. USERNAME
 * 	6. EVERYTHING ELSE REQUIERED
 * 	7. RENDERING 
 * 
 * 
 * 	X. FIX MEMORY LEAKS - IN PROGRESS
 * 	Y. COMMENTS!!!	- "WORKING" ON IT
 * 
 * 	IDEAS:
 *  Create new enemies and their creatures as neccessary scaling with difficulty
 * */

int Creature::counter=0;
Character characters[5];

/**
 * Temporary fix to "clearing" the console window
 * Part of a soon-to-come GUI
 * 	REMEMBER:
 * 	Windows console can only fit a little over 8000 lines of text
 * 
*/
void clearScreen(){
	for(size_t i=0;i<20;i++)
		std::cout<<std::endl;
	//Sleep(3000);
	//system("cls");
	std::cin.ignore(1000,'\n');
}
void save(){	//TODO: SAVE GAME STATE;

}
	/**
	 * STATES:
	 * 0- player saved and exited GAME NOT FINISHED
	 * 1- player lost ALL CREATURES DEAD
	 * 2- player won ALL ENEMIES DEFEATED
	*/

void endGame(int state){	//TODO: ENDGAME
	clearScreen();
	switch(state){
		case 0:
			std::cout<<"Game saved! See you soon!";
			break;
		case 1:
			std::cout<<"Game over! You lost!";
			break;
		case 2:
			std::cout<<"Good job! You won the game!\n You are the champion!";
			break;
		default:
			std::cout<<"Error: this shouldn't appear";
			break;
	}
	std::cout<<"\nThank you for playing.\n";
	exit(0);
}


/**
 * DESC:
 * Starts round, takes round number as num
 * A round is divided by turns, first the player can choose the action, and then the enemy responds to it
 * A round ends if either all of player's, or the enemy's creatures are dead, 
 * which the chooseNextValifCreature() func checks
 * 
 * At the end of the round all of the player's creatures's health points reset,
 * and the player returns to the round menu
*/

void startRound(size_t num){
	using std::cout,std::cin;
	int choice;
	bool badInput,specialAttackPossible;
	while(characters[num].firstValidCreature(num)>=0){
		if(characters[0].firstValidCreature(0)<0){
			endGame(1);
		}
		else if(characters[0].getCreatureInFocus().getLifePoints()<=0){
			cout<<"Your creature died!\n Choose next one to fight!";
			characters[0].playerChangeCreature();
		}
		characters[num].enemyChangeCreatureIfDead(num);

		clearScreen();
		cout<<"Round No. "<<num;
		cout<<"\n-----------";
		cout<<"\nYour creature:\n";
		cout<<characters[0].getCreatureInFocus().toString();

		cout<<"\n\nEnemy creature:\n";
		cout<<characters[num].getCreatureInFocus().toString();

		cout<<"\n\nChoose action: \n";
		cout<<"1.Attack\n2.Special attack\n3.Change creature\n";
		badInput=true;
		while(badInput){
			//cin.ignore(1000,'\n');
            cin>>choice;
            if(choice>=1&&choice<=3)
                badInput=false;
            else
               cout<<"\nWrong choice!\n";
		}
		specialAttackPossible=true;
		switch (choice){
		case 1:
			cout<<"Your";
			characters[0].attack(characters[num]);
			break;
		case 2:
			cout<<"Your";
			specialAttackPossible=characters[0].specialAttack(characters[num])==1;
			break;
		case 3:
			cout<<"Choose creature!\n";
			characters[0].playerChangeCreature();
			break;
		}
		
		if(specialAttackPossible){
			cout<<"Enemy ";
			characters[num].enemyResponse(characters[0]);
		}
			
	}
	//end of round
	characters[0].playerResetCreatures();
}

void gameLoop(){
	using std::cout,std::cin;

	char choice;
	size_t roundNum=0;

	while(roundNum<4){
		//Sleep(1000);
		clearScreen();

		cout<<"\n";
		cout<<characters[0].toString();
		cout<<"\n\nChoose action: \n";
		cout<<"1.Start next round\n2.Evolve creature\n3.Save and Quit\n";
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
		default:
			cout<<"\nWrong choice, try again: ";
			cin.clear();
		break;
		}
	}
}


void initializeCharacters(){

	characters[0]=Character("Player",0);
	for(size_t i=1;i<5;i++)
		characters[i]=Character("Enemy"+std::to_string(i),i);
}

void startGame(){
	srand(time(NULL));
	std::cout<<"Let's begin!\n";
	initializeCharacters();

	//Sleep(3000);		//for dramatic effect
	gameLoop();
	endGame(2);
}


int main()
{
	startGame();
	system("pause");	//TODO: DONT DO THAT
}



