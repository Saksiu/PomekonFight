#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <limits>
#include "creature.h"
#include "player.h"
/**
 * 
 * 	TODO:	
 * 	1.MAKE USER SELECT CREATURES FROM RANDOM SET, NOT ALL POSSIBLE CREATURES
 * 	2. EVERYTHING ELSE REQUIERED
 *
 * 
 * 
 * 
 * 
 * 
 * */

std::vector<Creature> creatures;
Player player=Player("Maks");
/**
 * Temporary fix to "clearing" the console window
 * Part of a soon-to-come GUI
 * 	REMEMBER:
 * 	Windows console can only fit a little over 8000 lines of text
 * 
*/
void clearScreen(){
	for(int i=0;i<50;i++)
		std::cout<<std::endl;
}


void attack(){
	std::cout<<"attacking!\n\n";
}

void changeCreature(){
	std::cout<<"changing!\n\n";
}

void evolveCreature(){
	std::cout<<"evolving!\n\n";
}

void gameLoop(){
	char choice;
	bool gameNotFinished=true;
	using std::cout,std::cin;

	while(gameNotFinished){
		//Sleep(1000);
		//system("CLS");
		cout<<"Choose action: \n";
		cout<<"1.Attack\n2.Change creature\n3.Evolve creature\n4.Quit\n";
		cin>>choice;

		switch (choice){
		case '1':
			attack();
			break;
		case '2':
			changeCreature();
			break;
		case '3':
			evolveCreature();
			break;
		case '4':
			exit(0);
			break;
		default:
			cout<<"\nWrong choice, try again: ";
		break;
		}
	}
	exit(0);
}



void chooseCreatures(){			//TODO: FIX CHECKING FOR BAD INPUT :v
	using std::cout,std::cin;
	int choice;
	for(int i=0;i<6;i++){
		cout<<"\nChoose your Creature ("<<i+1<<" out of 6):\n";

		for(int j=0;j<creatures.size();j++){
			cout<<"| "<<j+1<<". "<<creatures.at(j).toString()<<"|\n";
			cout<<"|----------------------------------------------------------------------------\n";
		}
		cout<<"\n";

		cin>>choice;
		clearScreen();
		if(choice<1||choice>=creatures.size()+1||cin.bad()){
			cout<<"\nWrong choice, try again";
			cin.clear();
			cin.ignore(1000,'\n');
			i--;
		}
		else{
			player.addCreature(creatures.at(choice-1));
			creatures.erase(creatures.begin()+choice-1);
		}
	}

	std::cout<<"\n"<<player.toString()<<"\n\n";
}

void createCreaturePool(){
	srand(time(NULL));

	Force tempForce;
	int forcePointer,tempStrength,tempLife;
	float tempAgility;

	for(int i=0;i<16;i++){
		forcePointer=rand()%6+1;
		switch (forcePointer){
		case 1: tempForce=Water;
			break;
		case 2: tempForce=Earth;
			break;
		case 3: tempForce=Air;
			break;
		case 4: tempForce=Fire;
			break;
		case 5: tempForce=Ice;
			break;
		case 6: tempForce=Steel;
			break;
		default: tempForce=Steel;
			break;
		}
		tempStrength=rand()%20+20;
		tempLife=rand()%70+80;
		tempAgility=rand()%10+1-((float)(rand()%10+1)/10.0);

		creatures.push_back(Creature("Creature_"+std::to_string(i+1),tempForce,tempStrength,tempLife,tempAgility));
	}
}

void startGame(){
	using std::cout,std::endl;
	cout<<"Let's begin!"<<endl;
	//Sleep(3000);
	createCreaturePool();
	chooseCreatures();
	//gameLoop();
}


int main()
{
	startGame();
	system("pause");	//TODO: DONT DO THAT
}



