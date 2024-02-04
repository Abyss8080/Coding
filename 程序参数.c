#include <stdio.h>
main(int argc, char *argv[])

{

	int j;

	for (j = argc - 1; j >= 0; j--)
		printf("%s\n", argv[j]);
}
