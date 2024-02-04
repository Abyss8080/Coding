#include <stdio.h>
#include <stdlib.h>

int main() {
	int max = 20;
	for (int i = 0; i < max; ++i) {
		if (i == 10)
			break;
		printf("%d\n", i);
	}

	return 0;

}