#include <stdio.h>

int i;
void prt();
int main() {

	for (i = 0; i < 5; i++) {
		prt();

	}/*��һ��ѭ����i==5������һ��ѭ�������ѭ��*/
	return 0;

}


void prt() {
	for (i = 0; i < 5; i++) {
		printf("%c", '*');

	}
	printf("\n");
}