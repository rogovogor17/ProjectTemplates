#include <stdio.h>

int main(int argc, char **argv) {

	if (argc > 1)
		printf("argv[1]: %s\n", argv[1]);
	else
		printf("Hello, world!\n");

	return 0;
}
