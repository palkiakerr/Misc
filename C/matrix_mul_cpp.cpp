#include <stdio.h>
#include <stdlib.h>  //for atof() function

// Function to calculate the dot product of two vectors v1 and v2
float dotprod(float v1[], float v2[], int n){
	float total = 0;

	for(int i = 0; i<n; i++){

		total += v1[i]*v2[i];
	}
	
	return(total);
}


int main(int argc, char *argv[]){

	//Assigns matrix dimension
	int x1, x2, y1, y2; 
	sscanf(argv[1], "%dx%d", &y1, &x1);
	sscanf(argv[3], "%dx%d", &y2, &x2);

	if(x1 != y2){
		printf("That multiplication is not possible with the given dimensions\n");
		return 1;
	}

	//Initalise empty system of floating point numbers
	float sys1[y1][x1], sys2[x2][y2];
	float results[y1][x2];

	
	//
	// Entire secion is reading in matrices
	//
	// Access 1st matrix file

	// target holds the name of the accessed file
	char target[100];
	sscanf(argv[2], "%s", target);

	//Open file
	FILE *mtrx_source;
	mtrx_source=fopen(target,"r");

	//Loop to read file into sys1 array
	
	for(int y = 0; y<y1; y++){
		for (int x = 0; x<x1; x++){

			char buffer[225];
			fscanf(mtrx_source, "%s", buffer);
			sys1[y][x] = atof(buffer);
		}
	}
	fclose(mtrx_source);



	//Access 2nd matrix file
	sscanf(argv[4], "%s", target);
	mtrx_source=fopen(target,"r");

	//Loop to read file into sys2 array
	for(int y = 0; y<y2; y++){
		for (int x = 0; x<x2; x++){

			char buffer[225];
			fscanf(mtrx_source, "%s", buffer);
			sys2[x][y] = atof(buffer);
		}
	}
	fclose(mtrx_source);

	//
	// Now can begin performing the multiplicaiton
	// 

	for(int y = 0; y<y1; y++){
		for(int x=0; x<x2; x++){
			results[x][y] = dotprod(sys1[y], sys2[x], y2);
		}

	}


	//Now print out final matrix
	//Print row-reduced matrix

	for(int y=0; y<(y1); y++){
		for(int x=0; x<(x2); x++){
			printf("%f    ", results[x][y]);
		}
		printf("\n");
	}


}