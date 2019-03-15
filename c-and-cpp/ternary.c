#include "stdio.h"

void main() {

	bool amICool = true;

	//ternary operation
	amICool ? printf("Yeah") : printf("Nope"); 

	//which is equivalent to:
	if (amICool == true) {
		printf("Yeah");
	}
	else {
		printf("Nope");
	}


}
