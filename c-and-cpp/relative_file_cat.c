#include <stdio.h>
#include <string.h>

//macros for cstrings; S, M, and L versions
#define SSTRING 30
#define MSTRING 120
#define LSTRING 600

//debugging purposes
//#define STOP_IF_EOF for(int iter = 0; iter < strlen(buff); iter++) if (buff[iter] == EOF) {cont = 0;}

//struct for holding info on a cat
typedef struct {
	bool isEmpty; //marks the record as either valid(false) or empty(true)
	unsigned int ID;
	char name[SSTRING] = "";	//needs to be initialised so strcat will work
	char owner[SSTRING] = "";
	unsigned int age;
	char status[SSTRING] = "";
} CAT;


//in: name of the file 
void writeCatFromStdin(char *fname){
	FILE *f;
	f = fopen(fname, "wb");	//open file in binary write mode

	if (!f) {
		printf("Unable to open file %s;\n", fname);
	}
	else {
		printf("File successfully opened;\n");
		int i = 1;
		char buff[SSTRING]; //a buffer to hold input

		//ask for first cat's name and copy in buffer; strtok is necessary to remove newline from fgets() formatting
		printf("Enter name of the cat: ");
		fgets(buff, SSTRING - 1, stdin); strtok(buff, "\n");

		while(buff[0] != '\n') {	//while user doesn't input just a newline, continue asking for input
			CAT c;

			c.isEmpty = 0;			//by default the block is marked as valid
			c.ID = i;				//each cat is assigned unique id

			strcat(c.name, buff);	//commit name to the struct

			printf("Enter the owner of the cat: ");
			fgets(buff, SSTRING - 1, stdin); strtok(buff, "\n");
			strcat(c.owner, buff);

			c.age = i % 2 + 2;	//just some number based on the order of input; could be randomly generated or input by user

			printf("Enter the status of the cat (alive/dead) : ");
			fgets(buff, SSTRING - 1, stdin); strtok(buff, "\n");
			strcat(c.status, buff);

			fwrite(&c, sizeof(CAT), 1, f);	//commit to disk
			i++;

			//only AFTER this ask for the name of the (next) cat in the loop
			printf("Enter name of the cat, or hit ENTER to quit: ");
			fgets(buff, SSTRING - 1, stdin); strtok(buff, "\n");
		}
	fclose(f);
	}
}


//i: the name of file
void writeCat(char *fname) {
	FILE *f;
	f = fopen(fname, "wb");	//open file in binary write mode

	if (!f) {
		printf("Unable to open file %s;\n", fname);
	}
	else {
		printf("File successfully opened;\n");
		int i;
		for (i = 0; i < 21; i++) {	//write 20 cats
			CAT c;
			c.isEmpty = 0;			//by default the block is marked as valid
			c.ID = i + 1;				//each cat is assigned unique id
			strcat(c.name, "Mitzi");
			strcat(c.owner, "Dr. Schrodinger");
			c.age = i % 2 + 2;
			strcat(c.status, "Alive");
			fwrite(&c, sizeof(CAT), 1, f);
		}
		fclose(f);
	}
}


//i: the name of file
void displayCat(char *fname) {
	FILE *f;
	f = fopen(fname, "rb");	// open file in binary read mode

	if (!f) {
		printf("Unable to open file %s;\n", fname);
	}
	else {
		printf("File successfully opened;\n");

		//get the number of records by dividing file size by size of a record
		fseek(f, 0, SEEK_END);
		int noOfRecords = ftell(f)/sizeof(CAT);

		fseek(f, 0, SEEK_SET);	//rewind file
	
		//sequentially traverse file
		for (int i = 0; i < noOfRecords; i++) {
			//declare a buffer CAT struct to hold values in memory
			CAT c;
			//load each CAT record into memory and display the vals of its fields
			fread(&c, sizeof(CAT), 1, f);
			printf("%d\n", c.ID);
			printf("%s\n", c.name);
			printf("%s\n", c.owner);
			printf("%d\n", c.age);
			printf("%s\n", c.status);
			printf("\n");
		}
		fclose(f);
	}
}

//i: the name of file
void writeCatToFile(char *fname) {
	char gname[MSTRING];	//the name of the result file (has to be M in case fname is SSTRING long)
	strcpy(gname, fname);	//copy the name < fname.dat/fname.bin > into gname
	strtok(gname, ".");		//strip the extyension off the name
	strcat(gname, ".txt");	//and replace it w/ .txt

	FILE *f;
	FILE *g;
	f = fopen(fname, "rb");	//open the source file in binary read
	g = fopen(gname, "w");	//and the result file in normal write 

	if (!f) {
		printf("Unable to open file %s;\n", fname);
	}
	else {
		printf("File successfully opened;\n");

		//get the number of records by dividing file size by size of a record
		fseek(f, 0, SEEK_END);	
		int noOfRecords = ftell(f) / sizeof(CAT);

		fseek(f, 0, SEEK_SET);
		if (!g) {
			printf("Unable to open file %s;\n", gname);
		}
		else {
			for (int i = 0; i < noOfRecords; i++) {
				CAT c;
				fread(&c, sizeof(CAT), 1, f);//load each CAT block into c 
				fprintf(g, "ID:		%d\n", c.ID);	//and write the vals of its fields into the text file
				fprintf(g, "NAME:		%s\n", c.name);
				fprintf(g, "OWNER:		%s\n", c.owner);
				fprintf(g, "AGE:		%d\n", c.age);
				fprintf(g, "STATUS:		%s\n", c.status);
				fprintf(g, "\n");
			}
		}
		fclose(f); fclose(g);
	}
}


int main() {
	char file[SSTRING];

	printf("Input a filename to open: ");
	fgets(file, SSTRING - 1, stdin); strtok(file, "\n");

	writeCatFromStdin(file);
	displayCat(file);
	writeCatToFile(file);

	getchar();
	return 0;
}
