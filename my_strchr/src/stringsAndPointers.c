/*
 * strchr.c
 *
 *  Created on: 30 Nov 2016
 *      Author: Digilogue
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t my_strlen(const char* str);
char* my_strchr(const char* str, int c);

int main(void) {
	printf("This is my_strchr!\n");

	size_t len = my_strlen("Hello world");
	printf("Length is %lu \n", len);

	char* result = my_strchr("Cola", 'l');
	printf("%s\n", result);
	char* tst = strchr("Hello there, Give me some beer please...", 'G');
	printf("%s\n", tst);

	return 0;
}

size_t my_strlen(const char* str) {

	printf("%c%c\n", str[1], str[2]);

	if (str == NULL) {
		return 0;
	}

	int length = 0;
	const char *ch = str;
	while (*ch != '\0') {
		length++;
		ch++;
	}

	return length;
}

char* my_strchr(const char* str, int c) {

	printf("%p\n", str);

	while (*str != '\0') {
		if (*str == c) {
			return (char*) str;
		}
		str++;
	}

	return NULL;
}

