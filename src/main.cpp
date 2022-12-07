#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <limits>
#include "creature.h"
#include "character.h"
/**
 * 	PRIORITY:
 * 	CHANGE SETTERS IN CHARACTER AND CREATURE CLASSES TO PASS REFERENCES INSTEAD OF LOCAL VALUES
 *  DOESN'T UPDATE CREATURE HEALTH
 * 
 * 	TODO:	
 * 	
 * 	1. MAIN GAMEPLAY LOGIC - IN PROGRESS
 * 	2. UI FOR FIGHTS
 *  3. PLAYERSTATE SAVE/LOAD SYSTEM
 * 	4. DIFFICULTY
 *	5. USERNAME
 * 	6. EVERYTHING ELSE REQUIERED
 * 
 * 
 * 
 * 	X. FIX MEMORY LEAKS - IN PROGRESS
 * 	Y. COMMENTS!!!	- "WORKING" ON IT
 * 
 * 	IDEAS:
 *  Create new enemies and their creatures as neccessary scaling with difficulty
 * */

std::vector<Creature> creatures;
Character player=Character("Maks");
Character enemies[4];
bool roundFinished;
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
void save(){	//TODO: SAVE GAME STATE;

}

void endGame(){	//TODO: ENDGAME
	clearScreen();
	std::cout<<"Good job! You finished the game!\n";
	std::cout<<"Thank you for playing.\n";
	exit(0);
}
void doDamage(int enemyNum){
	enemies[enemyNum].getFocusedCreature().setlifePoints(2);
}

void attack(int enemyNum){
	clearScreen();
	std::cout<<"Your creature strength: "<<player.getFocusedCreature().getStrength();
	std::cout<<"\nEnemy creature health before attack: "<<enemies[enemyNum].getFocusedCreature().getlifePoints();
	doDamage(enemyNum);
	std::cout<<"\nEnemy creature health after attack: "<<enemies[enemyNum].getFocusedCreature().getlifePoints();
}

void specialAttack(int enemyNum){
	std::cout<<"special attack!\n\n";
}

//To put different creature for use in battle round
int changeCreature(){
	clearScreen();
	std::cout<<"Choose creature: \n";
	std::cout<<player.toString();
	int choice;
	std::cin>>choice;
	if(choice>=1&&choice<=6)
		return choice;
	else{
		std::cout<<"\nWrong choice!\n";
		return changeCreature();
	}
	
}
void healCreature(){
	std::cout<<"healing!\n\n";
}
void evolveCreature(){
	std::cout<<"evolving!\n\n";
}

//Enemy changing their currently fighting creature to the first non-deafeted creature
//returns negative value if all enemy creatures defeated (round won)
int enemyDecideCreature(int enemyNum){
	for(int i=0;i<4;i++)
		if(enemies[enemyNum].getCreatureAt(i).getlifePoints()>=0)
			return i;
	return -1;
}

void checkIfRoundFinished(int roundNum){
	//true if all enemy creatures have no lives(player won round)
	if(enemyDecideCreature(roundNum)==-1)	
		roundFinished=true;
	else							//TODO: add return status for ending round (player lost)
		roundFinished=false;
}
void startRound(int num){
	using std::cout,std::cin;
	char choice;

	roundFinished=false;
	while(!roundFinished){
		clearScreen();
		enemies[num-1].putFocusOnCreature(enemyDecideCreature(num-1));

		cout<<"Round No. "<<num;
		cout<<"\nYour creature:\n"<<player.getFocusedCreature().toString();
		cout<<"\n\nEnemy creature:\n"<<enemies[num-1].getFocusedCreature().toString();

		cout<<"\n\nChoose action: \n";
		cout<<"1.Attack\n2.Special attack\n3.Change creature\n4.Heal creature\n";

		cin>>choice;

		switch (choice){		//TODO: wrong choice handler
		case '1':
			attack(num-1);
			break;
		case '2':
			specialAttack(num-1);
			break;
		case '3':
			player.putFocusOnCreature(changeCreature()-1);
			break;
		case '4':
			healCreature();
			break;
		default:
			cout<<"\nWrong choice, try again: ";
			cin.clear();
		break;
		}
		checkIfRoundFinished(num-1);
	}
}

void gameLoop(){
	char choice;
	bool gameNotFinished=true;
	int roundNum=0;
	using std::cout,std::cin;

	while(roundNum<4){
		//Sleep(1000);
		clearScreen();
		cout<<"\n"<<player.toString()<<"\n\n";
		cout<<"Choose action: \n";
		cout<<"1.Start next round\n2.Evolve creature\n3.Save and Quit\n";
		cin>>choice;

		switch (choice){
		case '1':
			roundNum++;
			startRound(roundNum);
			break;
		case '2':
			evolveCreature();
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

void createEnemyCharacters(){
	for(int i=0;i<std::size(enemies);i++){
		enemies[i]=Character("Enemy_"+std::to_string(i+1));

		for(int j=0;j<4;j++){
			enemies[i].addCreature(creatures.at(j));
			creatures.erase(creatures.begin()+j);
		}
	}
	//WARNING: DELETES ALL REMAINING CREATURES FROM THE INITIAL RANDOM POOL
	creatures.clear();
}


void chooseCreatures(){			/*TODO: FIX CHECKING FOR BAD INPUT :v*/
	using std::cout,std::cin;

	std::vector<Creature> playerPool;
	/**
	 * WARNING: DOESN'T GIVE EXACTLY HALF OF THE WHOLE POOL TO CHOOSE FROM
	 * AS IT DELETES ELEMENTS OF THE POOL WHILE ITERATING THROUGH IT!!!
	 * GIVES 10 OUT OF 30 GOOD ENOUGH FOR NOW
	 */
	for(int i=0;i<creatures.size();i++){		
		if(i%2==0){
			playerPool.push_back(creatures.at(i));
			creatures.erase(creatures.begin()+i);
		}
	}


	int choice;
	for(int i=0;i<6;i++){
		cout<<"\nChoose your Creature ("<<i+1<<" out of 6):\n";

		for(int j=0;j<playerPool.size();j++){
			cout<<"| "<<j+1<<". "<<playerPool.at(j).toString()<<"|\n";
			cout<<"|-------------------------------------------------------------------------------------\n";
		}
		cout<<"\n";

		cin>>choice;
		clearScreen();
		if(choice<1||choice>=playerPool.size()+1||cin.bad()){
			cout<<"\nWrong choice, try again";
			cin.clear();
			cin.ignore(1000,'\n');
			i--;
		}
		else{
			player.addCreature(playerPool.at(choice-1));
			playerPool.erase(playerPool.begin()+choice-1);
		}
	}
	//Return not chosen creatures back to the pool
	for(int i=0;i<playerPool.size();i++)
		creatures.push_back(playerPool.at(i));
	playerPool.clear();
	//std::cout<<"\n"<<player.toString()<<"\n\n";
}

void createCreaturePool(){	//TODO: Better random creature creation tool (naming, balance)
	srand(time(NULL));

	Force tempForce;
	int forcePointer,tempStrength,tempLife;
	float tempAgility;

	for(int i=0;i<30;i++){
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

		creatures.push_back(
			Creature("Creature_"+std::to_string(i+1),tempForce,tempStrength,tempLife,tempAgility));
	}
}

void startGame(){
	//using std::cout,std::endl;
	std::cout<<"Let's begin!\n";
	//Sleep(3000);		//for dramatic effect
	createCreaturePool();
	chooseCreatures();
	createEnemyCharacters();
	gameLoop();
	endGame();
}


int main()
{
	startGame();
	system("pause");	//TODO: DONT DO THAT
}



