#include <stdio.h>
#include <stdlib.h>

int main() {
	int (*pb)[3];
	int pc[3][3] = {{11, 12, 13}, {21, 22, 23}, {31, 32, 33}};
	int i = 1;
	int j = 2;
	int k = 3;
	for (int m = 0; m < 3; ++m) {
		for (int n = 0; n < 3; ++n) {
			printf("pc[%d][%d]=%d   ", m, n, pc[m][n]);
		}
		printf("\n");
	}


	pb = pc;
	printf("\n%p\n", &pb);
	printf("\n%p\n", &pc[2][2]);
	printf("\n(*(pc+1))[2]=%d\n", (*(pc + 1))[2]);
	printf("\n(*pb)[0]=%d\n", (*pb)[0]);
	printf("\n(*(pb+1))[0]=%d\n", (*(pb + 1))[0]);


	return 0;
}