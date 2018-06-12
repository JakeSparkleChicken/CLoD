/*
 * files.h
 *
 *  Created on: Jun 11, 2018
 *      Author: dok
 */

#ifndef FILES_H_
#define FILES_H_

FILE* fileOpen(char* filename);
void fileClose(FILE* filename);
void contactsFromLines(FILE* file, contact** headRef);
void contactsToLines(contact** headRef, FILE* file);

#endif /* FILES_H_ */
