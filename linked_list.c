/*
 * linked_list.c
 *
 *  Created on: Jun 11, 2018
 *      Author: dok
 */
#include "linked_list.h"
#include <assert.h>
#include <stdio.h>

contact* createList() {
	contact* head;
	return head;
}
void createContact(contact** headRef, contact* new) {
	assert (headRef != NULL && new != NULL);
	struct node* head = *headRef;
	struct node* prev = NULL;
	while (head != NULL && new->lname > head->lname) {
		prev = head;
		head = head->next;
	}
	contact* newNode;
	newNode->fname = new->fname;
	newNode->lname = new->lname;
	newNode->email = new->email;
	newNode->number = new->number;
	if (prev!= NULL) {
		prev->next = newNode;
	}
	else {
		*headRef = newNode;
	}
	newNode->next = head;
}

void fetchContact(contact** headRef, char* name) {
	assert (headRef!= NULL && name != NULL);
	contact* head = headRef;
	while ((head != NULL) && ((*name != head->fname)||(*name != head->lname))) {
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

