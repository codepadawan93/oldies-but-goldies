#include "stdio.h"


void main()
{
	//declare everything
	int n, i, j, k, c = 0;
	float A[100];

	//read data from user
	printf("Input number of elements of A: \n");
	scanf("%d", &n);

	printf("Input elements of A: \n");
	for (i = 0; i < n; i++) {
		printf("A[%d]= ", i);
		scanf("%f", &A[i]);
	}


	//business logic
	for (i = 0; i < n;) {				//iterate over A
		if (A[i] == 0) {				//if any element is 0-
			for (k = i; k < n; k++) {	//shift array one index down, overwriting the 0
				A[k] = A[k + 1];
			}
			n--;						//decrement n, as 1 element has been deleted
		}
		else
			i++;						//only increment i if there has been no deletion
	}


	//display results to user
	printf("Array A =");
	for (i = 0; i < n; i++) {
		printf("\t%.2f", A[i]);
	}
}

