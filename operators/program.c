#include <stdio.h>

int main() {

	int a = 1;
	int b = 2;

	int flagA = 1;
	int flagB = 0;

	int c = a + b;
	int boolResult = flagA || flagB;

	printf("+ c = %d\n", c);
	printf("|| boolResult = %d\n", boolResult);
}
