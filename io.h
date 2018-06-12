/*
 * io.h
 *
 *  Created on: Jun 11, 2018
 *      Author: dok
 */

#ifndef IO_H_
#define IO_H_
#include "linked_list.h"
#include <stdio.h>

contact* getNewContact();
int getCommand(FILE* file, contact** head);
void displayContact(contact* c);
char* getFilename();
char* contactToFind();

#endif /* IO_H_ */
