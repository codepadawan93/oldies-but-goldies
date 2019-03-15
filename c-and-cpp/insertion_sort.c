#include "stdio.h"


void main()
{
	//declare variables;
	int A[100];
	int n, i, j, val, prev;

	//get input from user;
	printf_s("Input number of elements of A: \n");
	scanf_s("%d", &n);

	printf_s("Input the elements of A: \n");
	for (i = 0; i < n; i++) {
		printf_s("A[%d]= ", i);
		scanf_s("%d", &A[i]);
	}

	//business logic;
	for (i = 0; i < n; i++) {			//traverse array
		val = A[i];						//save value of current element
		prev = i;						//remember the position of current element
		while ((prev > 0) && (A[prev - 1] > val)) {		//while current element is not first and the one before it is not greater
			A[prev] = A[prev - 1];						//copy the value to the left into the current value
			prev--;						//move leftwards
		}
		A[prev] = val;					//assign the saved value to the current value
	}

	//output results;
	printf_s("A = \t");
	for (i = 0; i < n; i++) {
		printf_s("%d\t", A[i]);
	}

}

