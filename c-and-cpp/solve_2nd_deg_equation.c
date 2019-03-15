#include "stdio.h"
#include "math.h"

void main() {
	//declare variables
	float a, b, c, delta, rootOne, rootTwo = 0;
	bool ok = false;

	//get data from user
	printf("Input coefficients: \n");
	scanf("%f%f%f", &a, &b, &c);

	//business logic
	delta = (b*b) - (4 * a * c);
	if (delta <= 0) {
		ok = false;
	}
	else {
		rootOne = (-1 * b + sqrt(delta)) / (2 * a);
		rootTwo = (-1 * b - sqrt(delta)) / (2 * a);
		ok = true;
	};

	//output results
	ok ? printf("The solutions are: { %f; %f};\n", rootOne, rootTwo) : printf("There are no solutions c R;\n");
}
