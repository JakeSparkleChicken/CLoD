/*
 * linked_list.c
 *
 *  Created on: Jun 11, 2018
 *      Author: dok
 */
#include "linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "io.h"
#include <stdlib.h>

contact* createList() {
	contact* head = (contact *)malloc(sizeof(contact));
	return head;
}
void createContact(contact** headRef, contact* new) {
	assert (headRef != NULL && new != NULL);
	contact* head = *headRef;
	contact* prev = NULL;
	while (head != NULL && new->lname > head->lname) {
		prev = head;
		head = head->next;
	}
	if (prev!= NULL) {
		prev->next = new;
	}
	else {
		*headRef = new;
	}
	new->next = head;
}

void fetchContact(contact** headRef, char* name) {
	assert (headRef!= NULL && name != NULL);
	contact* head = *headRef;
	while ((head != NULL) && ((strcmp(name, head->fname) !=0) || (strcmp(name, head->lname) != 0))) {
		head = head->next;
	}
	if (head != NULL) {
		displayContact(head);
	}
	else {
		printf("Contact not found\n");
	}
}

contact* sortByNumber(contact** headRef, char* number);
contact* sortByEmail(contact** headRef, char* email);
contact* deleteContact(contact** headRef, char* name);

