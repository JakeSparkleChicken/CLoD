/*
 * io.c
 *
 *  Created on: Jun 11, 2018
 *      Author: dok
 */

#include "io.h"
#include <stdio.h>
#include "files.h"
#include "linked_list.h"
#include <stdlib.h>
#include <string.h>

contact* getNewContact() {
	contact* new = (contact*)malloc(sizeof(contact));
	printf("\nEnter first name: ");
	scanf("%s", new->fname);
	printf("\nEnter last name: ");
	scanf("%s", new->lname);
	printf("\nEnter email address: ");
	scanf("%s", new->email);
	printf("\nEnter phone number: ");
	scanf("%s", new->number);
	printf("\n");
	return new;
}
int getCommand(FILE* file, contact** head) {
	printf("\nEnter command: \n");
	char com = getc(stdin);
	if (com == 'h') {
		printf("(s)ave and exit, (n)ew contact, (S)earch\n");
		return 0;
	}
	if (com =='s') {
		printf("Saving and exiting\n");
		contactToLine(head, file);
		return 1;
	}
	if (com == 'n') {
		createContact(head, getNewContact());
		return 0;
	}
	if (com == 'S') {
		char sname[32];
		printf("\nEnter name to search: \n");
		scanf("%s", sname);
		fetchContact(head, sname);
		return 0;
	}
	return 0;
}
void displayContact(contact* c) {
	printf("\nFirst name: %s\n", c->fname);
	printf("Last name: %s\n", c->lname);
	printf("Email address: %s\n", c->email);
	printf("Phone number: %s\n", c->number);
}
char* getFilename() {
	static char filename[40];
	printf("Enter filename of contact list:\n");
	scanf("%s", filename);
	return filename;
}
char* contactToFind();



