#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include "creature.h"
/**
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * */
std::vector<Creature> creatures;

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
		cout<<"Wybierz akcje: \n";
		cout<<"1.Atak\n2.Zmien stworzenie\n3.Ewolucja stworzenia\n4.Wyjdz\n";
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
			cout<<"\nnie wybrales zadnej z pozycji, sprobuj ponownie: ";
		break;
		}
	}
	exit(0);
}

void createCreaturePool(){
	srand(time(NULL));

	Force tempForce;
	int forcePointer,tempStrength,tempLife;
	double tempAgility;

	for(int i=0;i<10;i++){
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
		tempAgility=rand()%10+1-((double)(rand()%10+1)/10.0);

		creatures.push_back(Creature("Pomekon_"+std::to_string(i+2),tempForce,tempStrength,tempLife,tempAgility));
		std::cout<<"\n"<<creatures.at(i).toString()<<"\n";
	}
}

void startGame(){
	using std::cout,std::endl;
	cout<<"Zaczynamy gre!"<<endl;
	//Sleep(3000);
	createCreaturePool();

	//gameLoop();
}


int main()
{
	startGame();
	system("pause");
}



