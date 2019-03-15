/*
	sums two integers passed as command line args
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char *argv[]) {

	if (argc == 3) {
		char a[100], b[100];
		strcpy(a, argv[1]);
		strcpy(b, argv[2]);

		printf("Sum is: %d;", (atoi(a) + atoi(b)));
	}
	else{
		printf("Invalid parameter. Usage : cmdargs_test <operand1> <operand2>\n");
	}


	return 0;
}