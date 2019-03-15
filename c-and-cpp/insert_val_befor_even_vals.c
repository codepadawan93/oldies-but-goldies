#include "stdio.h"


void main()
{
    //declare variables;
	int A[100];
	int n, i, j, val;

	//get input from user;
	printf_s("Input number of elements of A: \n");
	scanf_s("%d", &n);

	printf_s("Input the elements of A: \n");
	for (i = 0; i < n; i++) {
		printf_s("A[%d]= ", i);
		scanf_s("%d", &A[i]);
	}

	printf_s("Input value to insert in A: \n");
	scanf_s("%d", &val);

	//business logic;
	for (i = 0; i < n; i++) {				//traverse array
		if (A[i]%2==0) {					//if element is even
			n++;							//make space for one extra element
			for (j = n - 1; j >= i; j--) {	//traverse array in reverse till the point the prev for has reached
				A[j+1] = A[j];				//move elements one index to right
			}
			A[i] = val;						//assign the specified value to the elem before an even elem 
			i++;							//increment i so we jump over the element we have moved previously
		}
	}

	//output results;
	printf_s("A = \t");
	for (i = 0; i < n; i++) {
		printf_s("%d\t", A[i]);
	}

}

