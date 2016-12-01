/*
 * strchr.c
 *
 *  Created on: 30 Nov 2016
 *      Author: gary
 */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t my_strlen();
char* my_strchr(const char* str, int c);

int main(void) {
	printf("This is my_strchr!\n");

	size_t len = my_strlen("Hello world");
	printf("Length is %lu \n", len);

	char greeting[5] = { 'C', 'O', 'L', 'A', '\0' };

	char* result = my_strchr("Cola", 'l');
	printf("%s\n", result);
	char* tst = strchr("Hello there, Give me some beer please...", 'G');
	printf("%s\n", tst);

}

size_t my_strlen(const char* str) {

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

