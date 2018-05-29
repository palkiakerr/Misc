#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char * argv[]){
	

	//seed random number generator
	int seed;
	sscanf(argv[1], "%d", &seed);
	
	srand(seed); 
	int i, stacks[3];

	//Generate the inital number of coins on each stack
	for(i=0; i<3; i++){
		stacks[i] = rand()%200;
	}

	int p1_remove, p2_remove, p1_score, p2_score, pile_no, games;

		//Player take their turns
		do{


			// Makes sure a valid pile is chosen for player 1
			pile_no = rand()%3;
			if(stacks[pile_no] == 0){continue;}

			p1_remove = rand()%(stacks[pile_no]+1);
			stacks[pile_no] -= p1_remove;
			if (stacks[pile_no] == 0){
				p1_score += 1;
			}

			if (stacks[0] ==0 && stacks[1] ==0 && stacks[2] ==0){break;}


			// Makes sure a valid pile is chosen for player 2
			pile_no = rand()%3;
			if(stacks[pile_no] == 0){continue;}

			p2_remove = rand()%(stacks[pile_no]+1);
			stacks[pile_no] -= p2_remove;
			if (stacks[pile_no] == 0){
				p2_score += 1;
			}

			if (stacks[0] ==0 && stacks[1] == 0 && stacks[2] == 0){break;}


		}while(1);

		if(p1_score > p2_score){printf("1");}
		else{printf("2");}

	return 0;
}