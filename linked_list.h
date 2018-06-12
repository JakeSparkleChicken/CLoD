/*
 * linked_list.h
 *
 *  Created on: Jun 11, 2018
 *      Author: dok
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct ContactElement{
	char fname[32];
	char lname[32];
	char email[32];
	char number[16];
	struct ContactElement* next;
}contact;

contact* createList();
void createContact(contact** headRef, contact* new);
void fetchContact(contact** headRef, char* name);
contact* sortByNumber(contact** headRef, char* number);
contact* sortByEmail(contact** headRef, char* email);
contact* deleteContact(contact** headRef, char* name);

#endif /* LINKED_LIST_H_ */
