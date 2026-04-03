#include <stdio.h>
#include "utils.h"

int main(int argc, char **argv) {

	if (argc > 1)
		printf("argv[1]: %s\n", argv[1]);
	else
		printf("Hello, world!\n");

	printf("result: %d\n", add(52, 0));

	return 0;
}
