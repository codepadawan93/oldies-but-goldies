/*
	<-- CAESAR CYPHER FUN LITTLE UTILITY -->
	version: 1.00
	completed: 22 apr 2017
	author: codepadawan
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//i: fname=the name of the file to open, res=an address to save the plaintext to
void getStringFromFile(char *fname, char **res) {
	FILE *f;
	f = fopen(fname, "r");

	if (!f) {
		printf("Unable to open file %s;\n", fname);
		exit(-1);
	}
	else {
		printf("File opened successfully;\n");

		//count the file size
		fseek(f, 0, SEEK_END);
		int fsize = ftell(f);
		rewind(f);

		//allocate needed memory
		(*res) = (char*)malloc(fsize+1);
		
		//save the string into memory
		fread((*res), fsize, 1, f);
		//(*res)[fsize + 1] = '\0';//terminate it with a \0 (NOT GOOD!!!)
		fclose(f);
	}
}


//in: the plaintext, the password, an address to save cyphertext to
void encryptText(char *txt, char *pass, char **res) {
	int txtlen = strlen(txt);
	int passlen = strlen(pass);

	//allocate memory for a result string
	(*res) = (char *)malloc(txtlen * sizeof(char)+1);

	//operate the encryption logic over the text and save the cyphertext in res
	for (int i = 0; i < txtlen; i += passlen) {
		for (int j = 0; j < passlen + 1; j++) {
			(*res)[i + j] = txt[i + j] + pass[j];
		}
	}
}


void decryptText(char *txt, char *pass, char **res) {
	int txtlen = strlen(txt);
	int passlen = strlen(pass);

	//allocate memory for a result string
	(*res) = (char *)malloc(txtlen * sizeof(char)+1);

	//operate the decryption logic over the text and save the plaintext in res
	for (int i = 0; i < txtlen; i += passlen) {
		for (int j = 0; j < passlen + 1; j++) {
			(*res)[i + j] = txt[i + j] - pass[j];
		}
	}
}


//in: fname=name of file, txt=the string with the text
void printStringToFile(char *fname, char *txt) {
	FILE *f;
	f = fopen(fname, "w+");
	fseek(f, 0, SEEK_SET);
	fwrite(txt, (strlen(txt)*sizeof(char)), 1, f);
	fclose(f);
}


//wrapper function for encrypting a file and saving the cypher
//text to another file
void enc(char *fname, char *pass) {
	char *result;
	char *cyphertext;
	getStringFromFile(fname, &result);	//save text as string
	encryptText(result, pass, &cyphertext);	//encrypt it
	strtok(fname, ".");			//create new file
	strcat(fname, "_enc.txt");	
	printStringToFile(fname, cyphertext); //save text to the new file
}


//wrapper function for decrypting a file and saving the resulting text
//into another file
void dec(char *fname, char *pass) {
	char *result;
	char *decryptedtext;
	getStringFromFile(fname, &result);	//save contents of file as string
	decryptText(result, pass, &decryptedtext);	//decrypt it with provided password
	strtok(fname, ".");		//create another file
	strcat(fname, "_dec.txt");
	printStringToFile(fname, decryptedtext);	//save text to the new file
}


int main(int argc, char *argv[]) {
	if (argc == 4) {
		//args should be passed like this:
		//caesar <-mode> <filename> <password>

		//this part is bugged, it does not properly do the comparations --fixed
		if (!strcmp(argv[1], "-dec")) {
			dec(argv[2], argv[3]);
			printf("Success. Exiting...");
			exit(0);
		}
		else if (!strcmp(argv[1], "-enc")) {
			enc(argv[2], argv[3]);
			printf("Success. Exiting...");
			exit(0);
		}
		else {
			printf("Error occurred, exiting...");
			printf("%s[", argv[1]);
			exit(-1);
		}
	}
	else {
		printf("Invalid parameters; Usage: %s <mode(-enc/-dec)> <source file> <password>", argv[0]);
	}
	getchar();
	return 0;
}