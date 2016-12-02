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
	printf("%s\n",result2);

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
	for (i = 0; i < sizeof(haystack); i++) {
		int hPos = mainPos;
		int nPos = 0;

		int j;
		for (j = 0; j < sizeof(needle); j++) {
			if (haystack[hPos] == needle[nPos]) {
				hPos++;
				nPos++;
			} else {
				break;
			}
		}

		if (nPos == sizeof(needle) - 2)
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
