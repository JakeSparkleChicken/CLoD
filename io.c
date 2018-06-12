/*
 * io.c
 *
 *  Created on: Jun 11, 2018
 *      Author: dok
 */

#include "io.h"
#include <stdio.h>

contact* getNewContact();
char* getCommand();
void displayContact();
char* getFilename() {
	char* filename;
	printf("Enter filename of contact list:\n");
	scanf("%s", filename);
	return filename;
}
char* contactToFind();



