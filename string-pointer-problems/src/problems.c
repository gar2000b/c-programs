/*
 * strchr.c
 *
 *  Created on: 01 Dec 2016
 *      Author: Digilogue
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void reasignPointer(int* valuePtr);
void modifyPointer(int* valuePtr);
char* my_strstr(const char* haystack, const char* needle);
int getNeedleInAHaystack(char* haystack, const char* needle);
int my_strcmp(const char* str1, const char* str2);

int main(void) {

	int value = 10;
	int* valuePtr = &value;
	printf("*valuePtr is: %d\n", *valuePtr);
	reasignPointer(valuePtr);
	printf("*valuePtr (after re-assignment) is: %d\n", *valuePtr);
	modifyPointer(valuePtr);
	printf("value is: %d\n", value);

	int result = getNeedleInAHaystack("azklneedleqbacszg", "needle");
	printf("getNeedleInAHaystack Result is: %d\n", result);

	char* result2 = my_strstr("azklneedleqbacszg", "needle");
	printf("%s\n", result2);

	int result3 = strcmp("zzz", "aaaa");
	printf("strcmp of zzz, aaaa: %d\n", result3);

	int result4 = my_strcmp("h", "a");
	printf("strcmp: %d\n", result4);

	return 0;
}

/**
 * Function to compare strings - same as strcmp.
 */
int my_strcmp(const char* str1, const char* str2) {

	if (str1 == NULL && str2 == NULL)
		return 0;

	if (str1 == NULL)
		return 0 - *str2;

	if (str2 == NULL)
		return *str1;

	int i;
	for (i = 0; i < strlen(str1); i++) {
		if (i == strlen(str2))
			return strlen(str1) - strlen(str2);

		if (str1[i] != str2[i])
			return str1[i] - str2[i];
	}

	if (strlen(str2) > strlen(str1))
		return strlen(str1) - strlen(str2);
	else
		return 0;
}

/*
 * Function to check for a string within a string (without thinking of pointers).
 * Note: characters are just integers (ASCII code of the character) in c.
 *
 * Returns position in haystack where needle was found.
 */
int getNeedleInAHaystack(char* haystack, const char* needle) {

	int mainPos = 0;

	int i;
	for (i = 0; i < strlen(haystack); i++) {
		int hPos = mainPos;
		int nPos = 0;

		int j;
		for (j = 0; j < strlen(needle); j++) {
			if (haystack[hPos] == needle[nPos]) {
				hPos++;
				nPos++;
			} else {
				break;
			}
		}

		if (nPos == strlen(needle))
			return mainPos;
		else
			mainPos++;
	}

	return -1;
}

/*
 * Function to check for a string within a string.
 * Note: characters are just integers (ASCII code of the character) in c.
 *
 * Returns a pointer to where the string needle present in the haystack or NULL.
 */
char* my_strstr(const char* haystack, const char* needle) {

	if (haystack == NULL || needle == NULL) {
		return NULL;
	}

	while (*haystack != '\0') {
		if (*haystack == *needle) {
			const char* h = haystack;
			const char* n = needle;
			while (*n != '\0' && *h == *n) {
				h++;
				n++;
			}
			if (*n == '\0') {
				return (char*) haystack;
			}
		}
		haystack++;
	}

	return NULL;
}

/**
 * Modifies the incoming pointer, therefore updated de-referenced value will
 * modify the incoming pointer passed in from the calling function.
 */
void modifyPointer(int* valuePtr) {
	printf("*valuePtr (after re-assignment / before modification) is: %d\n",
			*valuePtr);
	*valuePtr = 12;
	printf("%s\n", "pointer has been modified");
}

/**
 * Re-assigns pointer locally, therefore updated de-referenced value will not modify
 * the incoming pointer passed from the calling function.
 */
void reasignPointer(int* valuePtr) {
	valuePtr = (int *) malloc(sizeof(int));
	*valuePtr = 11;
	printf("Pointer after re-assignment (within called function): %d\n",
			*valuePtr);
}
