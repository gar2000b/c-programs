#include <stdio.h>

int main() {

	int apples = 5;
	int oranges = apples;

	apples = 4;

	printf("apples=%d oranges=%d\n", apples, oranges);

	return 0;
}
