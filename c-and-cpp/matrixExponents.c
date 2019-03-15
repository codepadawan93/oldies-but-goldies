//finds power of a matrix

#include "stdio.h"

void readMatrix(int *dim, float matrix[100][100]) {
	//reads a matrix with (dim) rows and cols
	int i = 0, j = 0;
	printf("Input dimension of matrix: \n");
	scanf("%d", &(*dim));
	for (i = 0; i < *dim; i++) {
		for (j = 0; j < *dim; j++) {
			printf("Input element at index [%d][%d]:\n", i, j);
			scanf("%f", &matrix[i][j]);
		}

	}
}


void printMatrix(int dim, float matrix[100][100]) {
	//prints a matrix with (dim) rows and cols
	int i = 0, j = 0;
	printf("Matrix is : \n");
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			printf("[%.2f]\t", matrix[i][j]);
		}
	printf("\n");
	}
}


void matrixCopy(int dim, float matrixFrom[100][100], float matrixTo[100][100]) {
	//copies the first matrix passed as arg into second matrix passed
	//note that (dim) of matrices has to be the same
	int i = 0, j = 0;
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			matrixTo[i][j] = matrixFrom[i][j];
		}
	}
}


void matrixMultiply(int dim, float matrixA[100][100], float matrixB[100][100], float matrixResult[100][100]) {
	//performs matrix multiplication on two matrices of (dim) rows and cols
	//matrix multiplication is not commutative; multiplication will take place in order of 
	//arguments passed (e.g. matrixA * matrixB = matrixResult)
	float elem = 0;
	int i = 0, j = 0, k=0;
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			matrixResult[i][j] = 0;
			for (k = 0; k < dim; k++) {
				matrixResult[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
}


void matrixExponent(int dim, float matrix[100][100], int pow, float matrixResult[100][100]) {
	//performs multiplication of a matrix with itself (pow) times
	int i, j;
	//use a buffer variable for holding temporary data
	float bufferMatrix[100][100];
	//construct identity matrix (any M^0 = I)
	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			if (i == j) {
				bufferMatrix[i][j] = 1;
			}
			else {
				bufferMatrix[i][j] = 0;
			}
		}
	}
	//if power is 0 save the identity matrix I into the result 
	if (pow == 0) {
		matrixCopy(dim, bufferMatrix, matrixResult);
	}
	else {
		//if power!=0, multiply matrix with itself pow times
		//save initial matrix into buffer
		matrixCopy(dim, matrix, bufferMatrix);
		for (i = 0; i < pow-1; i++) {
			matrixMultiply(dim, matrix, bufferMatrix, matrixResult);
			//save each subsequent result into buffer
			matrixCopy(dim, matrixResult, bufferMatrix);
		}
	}
	//this is an inelegant and counterintuitive way to do it but it works
}


void main(){
	//declare two matrices, one for data the other for results
	float A[100][100], C[100][100]; 
	int n = 0;
	//ask user for data
	readMatrix(&n, A);
	//display the matrix the user entered
	printMatrix(n, A);
	//here you could ask the user to provide the power to which to raise
	//the entered matrix

	//perform requested operation
	matrixExponent(n, A, 2, C);
	//display results
	printMatrix(n, C);
}

