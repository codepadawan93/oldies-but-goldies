//#include "conio.h"
#include "stdio.h"
#include "stdlib.h"

void readVector(int *dim, float **vect) {
	//reads and stores a vector with dim elements
	int i = 0;
	printf("Introdu dimensiunea vectorului:\n");
	scanf("%d", &(*dim));

	(*vect) = (float *) malloc((*dim) * sizeof(float));
	for (i = 0; i < (*dim); i++) {
		printf("Insereaza elementul la indicele [%d]:\n", i);
		scanf("%f", &(*vect)[i]);
	}
	
}


void printVector(int *dim, float **vect) {
	int i = 0;
	printf("Vectorul este:\n");
	for (i = 0; i < (*dim); i++) {
		printf("%.2f\t", (*vect)[i]);
	}
}




void main() {
	float *A;
	int n;

	readVector(&n, &A);
	printVector(&n, &A);


}
