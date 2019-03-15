/*
the teacher might insist on using the header file <malloc.h>, but 
this is nonstandard and deprecated (it's not even installed in 
visual studio 2015's compiler); use <stdlib.h> instead 
*/

#include <stdio.h> 
//#include <malloc.h> // <-- the library in question
#include <stdlib.h>


void readMatrix(int *m, int *n, float ***matrix) {
	//reads & stores a matrix with m cols and n rows with dynamic
	//memory allocation
	int i, j;
	printf("Input the row dimension of the matrix:\n");
	scanf("%d", &(*m));
	printf("Input the columns dimension of the matrix:\n");
	scanf("%d", &(*n));

	//allocate memory first for each row and then for each column
	(*matrix) = (float**) malloc((*m)*sizeof(float*));
	for (i = 0; i < *m; i++) {
		(*matrix)[i] = (float*) malloc((*n) * sizeof(float));
	}

	//assign elements
	for (i = 0; i < *m; i++) {
		for (j = 0; j < *n; j++) {
			printf("Input element [%d][%d]:\t", i, j);
			scanf("%f", &(*matrix)[i][j]);
		}
	}
}


void printMatrix(int *m, int *n, float ***matrix) {
	//prints a matrix with m cols and n rows 
	int i, j;
	for (i = 0; i < *m; i++) {
		for (j = 0; j < *n; j++) {
			printf("[%.2f]\t", (*matrix)[i][j]);
		}
		printf("\n");
	}
}


void main() {
	float **A; 
	int c, r;
	//read and print a matrix 
	readMatrix(&c, &r, &A);
	printMatrix(&c, &r, &A);
}