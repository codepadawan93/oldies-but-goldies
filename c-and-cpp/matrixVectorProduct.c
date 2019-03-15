#include <stdio.h> 



void readMatrix(int *dim, float matrix[100][100]) {
	//reads & stores a square matrix with (dim) cols and rows 
	int i, j;
	printf("Input the dimension of a square matrix:\n");
	scanf("%d", &(*dim));
	for (i = 0; i < *dim; i++) {
		for (j = 0; j < *dim; j++) {
			printf("Input element [%d][%d]:\t", i, j);
			scanf("%f", &matrix[i][j]);
		}
	}
}


void readVector(int *dim, float vector[100]) {
	//reads and stores a column vector
	int i;
	printf("Input the dimension of the vector:\n");
	scanf("%d", &(*dim));
	for (i = 0; i < *dim; i++) {
		printf("Input element [%d]:\t", i);
		scanf("%f", &vector[i]);
	}
}


void printMatrix(int dim, float matrix[100][100]) {
	//prints a square matrix with (dim) cols and rows 
	int i, j;
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			printf("[%.2f]\t", matrix[i][j]);
		}
		printf("\n");
	}
}


void printVector(int dim, float vector[100]) {
	//displays a column vector
	int i;
	for (i = 0; i < dim; i++) {
		printf("[%.2f]\n", vector[i]); 
	}
}


void multiplyVectorAndMatrix(int dim, float matrix[100][100], float vector[100], float result[100]) {
	//for this operation to be defined, dim has to be the same
	//pass arguments like this: M * V = V'
	int i, j;
	for (i = 0; i < dim; i++) {
		result[i] = 0;
		for (j = 0; j < dim; j++) {
			result[i] += matrix[i][j] * vector[j];
		}
	}
}


void main() {
	int m = 0;
	float A[100][100], V[100], R[100];
	//read the matrix and the column vector from user
	readMatrix(&m, A);
	readVector(&m, V);
	//multiply the matrix by the vector
	multiplyVectorAndMatrix(m, A, V, R);
	//print the resulting vector in column vector form
	printVector(m, R);
}