/*
 * main.c
 *
 *  Created on: Jun 11, 2018
 *      Author: dok
 */

#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "files.h"
#include "io.h"

int main() {
	contact* contactList = createList();
	char* filename = getFilename();
	FILE* file = fileOpenRead(filename);
	if (file != NULL)
	{
		contactsFromLines(file, &contactList);
	}
	file = fileOpenWrite(filename);
	while (1) {
		if (getCommand(file, &contactList) == 1) {
			break;
		}
	}

}
