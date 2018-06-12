/*
 * files.c
 *
 *  Created on: Jun 11, 2018
 *      Author: dok
 */

#include "linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

FILE* fileOpen(char* filename) {
	FILE* fp;
	fp = fopen(filename, "+w");
	return fp;
}
void fileClose(FILE* filename) {
	fclose(filename);
}
void ContactsFromLines(FILE* file, contact** headRef) {
	assert(file != NULL && headRef != NULL);
	char ch;
	char* str[32];
	while (1) {
		ch = fgetc(file);
		if (ch == EOF) {
			*headRef->next = NULL;
			break;
		}
		while (1) {
			if (ch == '\n') {
				break;
			}
			int i = 0;
			while (1) {
				if (ch == '\t') {
					break;
				}
				str[i] = ch;
				i++;
				ch = fgetc(file);
			}
			*headRef->fname = str;
			while (1) {
				if (ch == '\t') {
					break;
				}
				str[i] = ch;
				i++;
				ch = fgetc(file);
			}
			*headRef->lname = str;
			while (1) {
				if (ch == '\t') {
					break;
				}
				str[i] = ch;
				i++;
				ch = fgetc(file);
			}
			*headRef->email = str;
			while (1) {
				if (ch == '\t') {
					break;
				}
				str[i] = ch;
				i++;
				ch = fgetc(file);
			}
			*headRef->number = str;
			*headRef->next = (contact*)malloc(sizeof(contact));
			*headRef = *headRef->next;
		}

	}
}
void contactToLine(contact** headRef, FILE* file) {
	assert (headRef != NULL);
	char* line[255];
	while (*headRef != NULL) {
		line = *headRef->fname;
		strcat(line, '\t');
		strcat(line, *headRef->lname);
		strcat(line, '\t');
		strcat(line, *headRef->email);
		strcat(line, '\t');
		strcat(line, *headRef->number);
		strcat(line, '\n');
		*headRef = *headRef->next;
		fputs(line, file);
	}
}


