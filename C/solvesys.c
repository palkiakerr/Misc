// Author: Kerr Maxwell
// mxwkerr@gmail.com / 2260552m@student.gla.ac.uk
//
//   A program which reads in an augmented matrix from a file
//   and applys naive Gaussian elimination to reduce the
//   matrix to row-echelon form [working] and then perform
//   back-substitution to solve the system [non working]
//
// Input format: solvesys [ file.matrix ]	[ n ]
//  
//   Where n is the dimension of the unaugmented
//   square matrix
//
//
// Example file.matrix:  6  -2  2   4  16
//                       12 -8  6  10  26
//                       3 -13  9   3 -19
//                      -6   4  1 -18 -34
// 
// An example file "test.matrix" is given for use


#include <stdlib.h>  //for atof() function
#include <stdio.h>

int main(int argc, char * argv[]){

	//Assigns matrix dimension
	int n;
	sscanf(argv[2], "%d", &n);

	//Initalise empty system of floating point numbers
	float sys[n][n];
	float results[n];

	//Access matrix file
	char target[sizeof(argv[1])/sizeof(char)+1];
	sscanf(argv[1], "%s", target);
	FILE *mtrx_source;
	mtrx_source=fopen(target,"r");


	//Loop to read file into sys array
	
	for(int i = 0; i<(n); i++){
		for (int j = 0; j<(n); j++){

			char buffer[225];
			fscanf(mtrx_source, "%s", buffer);
			sys[i][j] = atof(buffer);
		}
		char buffer[225];
		fscanf(mtrx_source, "%s", buffer);
		results[i] = atof(buffer);

		}

	

	
    //
	//Perform Foreward Elimination
    //

	//Iterate over pivot row
	for(int k = 1; k<(n); k++){

		//Perform pivot subtraction on each subsuquent row
		for(int i=k+1; i<(n+1); i++){

			float ratio = (sys[i-1][k-1]/sys[k-1][k-1]);

			//Element-wise subtraction
			for(int j=k; j<(n+1); j++){
				sys[i-1][j-1] = sys[i-1][j-1] - ratio*sys[k-1][j-1];
			}
			//Update results table
			results[i-1] = results[i-1] - ratio*results[k-1];
		}
	}
	
	//Print row-reduced matrix
	for(int i=0; i<(n); i++){
		for(int j=0; j<(n); j++){
			printf("%f       ", sys[i][j]);
		}
		printf("%f", results[i]);
		printf("\n");
	}
	



	//
	//Perform Reverse Subsitiution
	//

	float sum; //Holds working total or RHS
	float computed[n]; //RHS after all substitution
	int iterloop=1;

	//Find first variable to begin substitution 
	computed[n-1] = results[n-1]/sys[n-1][n-1];
    
	//
    //UP TO THIS POINT IS  WORKING
	//

	for(int i=n-2;i>-1;i--){
		sum = results[i];

		for(int j=0; j<iterloop; j++){

			sum -= sys[i][n-1-j]*computed[n-1-j];
		}
		computed[i] = sum/sys[i][i];
		iterloop++;
	}


	//Print out computed solutions
	for(int i=0;i<n;i++){
		printf("x%d = %f\n", i+1, computed[i]);
	}

	

	return 0;
}