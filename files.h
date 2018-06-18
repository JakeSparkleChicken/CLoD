/*
 * files.h
 *
 *  Created on: Jun 11, 2018
 *      Author: dok
 */

#ifndef FILES_H_
#define FILES_H_
#include "linked_list.h"
#include <stdio.h>


FILE* fileOpenRead(char* filename);
FILE* fileOpenWrite(char* filename);
void fileClose(FILE* filename);
void contactsFromLines(FILE* file, contact** headRef);
void contactToLine(contact** headRef, FILE* file);

#endif /* FILES_H_ */
