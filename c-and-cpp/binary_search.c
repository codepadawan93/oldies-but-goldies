#include <stdio.h>

void main() {
	//declare variables
	float A[100];
	int n, mid, liml, limr, ok = 0;
	float val;

	//receive input
	printf("Input no. of vals in A:\n");
	scanf("%d", &n);

	printf("Input vals in A:\n");
	for (int i = 0; i < n; i++) {
		scanf("%f", &A[i]);
	}

	printf("Input val to be searched for:\n");
	scanf("%f", &val);

	//business logic
	//set the left and right limits to the extremes of the array so the initial middle index can be found
	liml = 0;
	limr = n;
	mid = ((liml + limr) / 2);				//we set the initial middle point

	
	while (ok == 0) {
		mid = ((liml + limr) / 2);			//update mid for every iteration
		if (A[mid] == val) {				//if value at index mid is == to val searched for, set flag to 1
			ok = 1;
		}
		else if (A[mid] < val) {			//if less than val, set left limit to the previous mid value to 
			liml = mid;						//search only in the right part of the array
		}
		else {								//if more than val, then only the left part has to be searched
			limr = mid;						//this goes on until ok is 0
		}
	}


	//output results to user
	if (ok == 1) {
		printf("Val was found at index: %d ;\n", mid);
	}
	else {
		printf("Val not present in array.\n");
	}
};
