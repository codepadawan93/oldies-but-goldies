#include "stdio.h"


void main()
{
	//declare everything
	int m, n, i, j, k, l;
	float A[100], B[100], C[200];

	//read data from user
	printf("Input number of elements of A: \n");
	scanf("%d", &n);

	printf("Input number of elements of B: \n");
	scanf("%d", &m);

	printf("Input elements of A: \n");
	for (i = 0; i < n; i++) {
		printf("A[%d]= ", i);
		scanf("%f", &A[i]);
	}

	printf("Input elements of B: \n");
	for (i = 0; i < m; i++) {
		printf("B[%d]= ", i);
		scanf("%f", &B[i]);
	}


	//business logic
	i = 0; j = 0; k = 0;			//reset counters

	while ((i < n) && (j < m)) {	//iterate over arrays until one is finished
		if (A[i] < B[j]) {			//if an element of A is < than an elem of B
			C[k] = A[i];			//push it into C
			i++; k++;
		}
		else {						//if not, push that element of B into C
			C[k] = B[j];			//and increment j, so the next comparison can take place
			j++; k++;
		}
	}

	if (i < n) {					//if A still has elements left, push them into C as well
		for (l = i; l < n; l++) {
			C[k] = A[l];
			k++;
		}
	}

	if (j < m) {					//if B still has elements left, push them into C as well
		for (l = i; l < n; l++) {	//note that both cannot happen at the same time
			C[k] = B[l];
			k++;
		}
	}


	//display results to user
	printf("Array C = \t");
	for (i = 0; i < (n + m); i++) {
		printf("%.2f\t", C[i]);
	}
}

