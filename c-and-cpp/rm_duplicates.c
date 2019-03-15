#include "stdio.h"


void main()
{
	//declare everything
	int n, i, j, k;
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
	for (i = 0; i < n; i++) {					//iterate over A; we assume A is sorted
		for (j = i + 1; j < n;) {				//iterate over A starting one index up and compare each value with the value preceding the starting index
			if (A[j] == A[i]) {					//if duplicate is found
				for (k = j; k < n; k++) {		//move right part of array one index down
					A[k] = A[k + 1];
				}
				n--;							//decrement size as one element has been deleted
			}
			else
				j++;							//only increment j if there is no duplicate
		}
	}


	//display results to user
	printf("Array A =");
	for (i = 0; i < n; i++) {
		printf("\t%.2f", A[i]);
	}
}