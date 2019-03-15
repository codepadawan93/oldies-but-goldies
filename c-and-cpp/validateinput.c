/*
Positive integer, validate existence (ex.: size for an array)
Integer within a given range [min, max]
Real within a given range [min, max]
Name of the week day – existence, domain
Name of the month – existence, domain
Password – min/max length, nature (>1 upper case, >1 lower case, >1 digit, >1 special character #$%&* must not be first or last)
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

bool validatePositiveInteger(char *x) {
	bool ok = false;
	int nums = 0; 
	for (int i = 0; i < strlen(x); i++) {
		if (x[i] >= '0' && x[i] <= '9') {//if formatted as integer
			nums++;					//if negative, not incremented as '-' and '.' not in ASCII ['0','9']
		}
	}

	if (nums == strlen(x)) {  //if all chars in string are nums, ret true
		ok = true;
	}
	return ok;
}

bool isIntInRange(char *x, int min, int max) {
	bool ok = false;
	int y;
	//TODO:: Adapt the function to get strings as inputs 
	int nums = 0;
	for (int i = 0; i < strlen(x); i++) {
		if (x[i] >= '0' && x[i] <= '9') {//if formatted as integer
			nums++;					//if negative, not incremented as '-' and '.' not in ASCII [0,9]
		}
	}

	if (nums == strlen(x)) {  //if all chars in string are nums
		y = atoi(x);
		if (y >= min && y <= max) {//and y is in range[min, max]
			ok = true;				//ret true
		}
	}
	return ok;
}

bool isDoubleInRange(char *x, double min, double max) {
	bool ok = false;
	int points = 0, nums = 0;
	//check how many decimal points are there
	for (int i = 0; i < strlen(x); i++) {
		if (x[i] >= '0' && x[i] <= '9' || x[i] == '.') {
			if (x[i] == '.') {
				points++;
			}
			nums++;
		}
	}
	
	double y = atof(x);
	//if between min and max and 0 or 1 decimal points and # chars that are numbers - # decimal points
	//equals length of string then ret true
	if (y >= min && y <= max && points <= 1 && (nums-points)==strlen(x)) {
		ok = true;
	}
	return ok;
}


bool isDayOfWeek(char *weekday) {
	bool ok = false;
	char weekdays[7][10] = {"luni", "marti" , "miercuri" , "joi" , "vineri" , "sambata" , "duminica"};

	for (int i = 0; i < 7; i++) {
		if (strcmp(weekday, weekdays[i])) {
			ok = true;
		}
	}
	return ok;
}

bool isNameOfMonth(char *month) {
	bool ok = false;
	char months[12][15] = { "ianuarie", "februarie" , "martie" , "aprilie" , "mai" , "iunie" , "iulie",
							"august", "septembrie" , "octombrie" , "noiembrie" , "decembrie"};

	for (int i = 0; i < 12; i++) {
		if (strcmp(month, months[i])) {
			ok = true;
		}
	}
	return ok;
}

bool validatePass(char *pass, int minlen, int maxlen) {
	bool ok = true;
	bool checks[5] = {false, false, false, false, false};
	int len = strlen(pass);
	char specials[] = "#$%&*";

	//Password – min/max length, nature (>1 upper case, >1 lower case, >1 digit, >1 special character #$%&* must not be first or last)
	//check length
	if (len >= minlen && len <= maxlen) {
		checks[0] = true;
	}
	for (int i = 0; i < len; i++) {
		//check if an uppercase letter is present
		if (pass[i] >= 'A' && pass[i] <= 'Z') {
			checks[1] = true;
		}
		//check if a lowercase letter is present
		if (pass[i] >= 'a' && pass[i] <= 'z') {
			checks[2] = true;
		}
		//check if a number is present
		if (pass[i] >= '0' && pass[i] <= '9') {
			checks[3] = true;
		}
	}
	//check if a special character is present and is not first or last
	for (int i = 1; i < len-1; i++) {
		for (int j = 0; j < strlen(specials); j++) {
			if (pass[i] == specials[j]) {
				checks[4] = true;
			}
		}
	}

	//return true if all checks are ok
	for (int i = 0; i < 5; i++) {
		if (checks[i] == false) {
			ok = false; //set flag to false if any condition is not met
		}
	}

	return ok;
}

int main() {
	char exampleString[100];
	bool ans = false;
	while (!ans) {
		printf("Input data: ");
		scanf("%s", &exampleString);
		ans = validatePass(exampleString, 8, 16);

		ans ? printf("Password ok.\n") : printf("Invalid input!\n");
	}
	return 0;
}