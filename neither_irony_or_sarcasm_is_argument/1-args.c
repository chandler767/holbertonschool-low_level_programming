#include <stdio.h>

int main(int argc, char *argv[])
 {
	int i = 0;
	while (i < argc) {
		printf("%s\n", argv[i]); /* print the argument */
		i++;
	}
	return 0;
 }
