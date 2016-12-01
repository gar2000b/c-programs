#include <stdio.h>

int addNumbers(int a, int b);

main(int argc, char *argv[]) {
	
	int total;
	total = addNumbers(2, 4);

	printf("total = %d\n", total);
	return 0;
}
