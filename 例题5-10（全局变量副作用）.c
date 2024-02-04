#include <stdio.h>

int i;
void prt();
int main() {

	for (i = 0; i < 5; i++) {
		prt();

	}/*第一次循环后i==5，于是一次循环后结束循环*/
	return 0;

}


void prt() {
	for (i = 0; i < 5; i++) {
		printf("%c", '*');

	}
	printf("\n");
}