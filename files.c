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

FILE* fileOpenWrite(char* filename) {
	FILE* fp;
	fp = fopen(filename, "w+");
	return fp;
}
FILE* fileOpenRead(char* filename) {
	FILE* fp;
	fp = fopen(filename, "r");
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
	fileClose(file);
}
void contactToLine(contact** headRef, FILE* file) {
	assert (headRef != NULL);
	contact* head = *headRef;
	while (head != NULL) {
		char tab = '\t';
		char newln = '\n';
		int i = 0;
		for (i = 0; head->fname[i] != '\0'; i++)
		{
			fputc(head->fname[i], file);
		}
		fputc(tab, file);
		for (i = 0; head->lname[i] != '\0'; i++)
		{
			fputc(head->lname[i], file);
		}
		fputc(tab, file);
		for (i = 0; head->email[i] != '\0'; i++)
		{
			fputc(head->email[i], file);
		}
		fputc(tab, file);
		for (i = 0; head->number[i] != '\0'; i++)
		{
			fputc(head->number[i], file);
		}
		fputc(newln, file);
		head = (head->next);
	}
	fileClose(file);
}


