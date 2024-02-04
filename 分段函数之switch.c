#include <stdio.h>

int main(void) {

	double x ;
	int t = x >= 0;
	scanf("%lf\n", &x);

	switch (t) {

		case 1:
			printf("y=2*x\n");
			break;
		case 0:
			printf("y=-1\n");
			break;
	}
	return 0;
}