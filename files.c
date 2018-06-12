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
#include <stdlib.h>
#include "io.h"
#include "files.h"

FILE* fileOpen(char* filename) {
	FILE* fp;
	fp = fopen(filename, "+w");
	return fp;
}
void fileClose(FILE* filename) {
	fclose(filename);
}
void contactsFromLines(FILE* file, contact** headRef) {
	assert(file != NULL && headRef != NULL);
	char ch;
	char str[32];
	contact* head = *headRef;
	while (1) {
		ch = fgetc(file);
		if (ch == EOF) {
			head->next = NULL;
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
			strcat(head->fname, str);
			while (1) {
				if (ch == '\t') {
					break;
				}
				str[i] = ch;
				i++;
				ch = fgetc(file);
			}
			strcat(head->lname, str);
			while (1) {
				if (ch == '\t') {
					break;
				}
				str[i] = ch;
				i++;
				ch = fgetc(file);
			}
			strcat(head->email, str);
			while (1) {
				if (ch == '\t') {
					break;
				}
				str[i] = ch;
				i++;
				ch = fgetc(file);
			}
			strcat(head->number, str);
			head->next = (contact*)malloc(sizeof(contact));
			head = head->next;
		}

	}
}
void contactToLine(contact** headRef, FILE* file) {
	assert (headRef != NULL);
	char* line;
	contact* head = *headRef;
	while (head != NULL) {
		char tab = '\t';
		char newln = '\n';
		line = (head->fname);
		strcat(line, &tab);
		strcat(line, head->lname);
		strcat(line, &tab);
		strcat(line, head->email);
		strcat(line, &tab);
		strcat(line, head->number);
		strcat(line, &newln);
		head = (head->next);
		fputs(line, file);
	}
}


