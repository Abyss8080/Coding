#include <stdio.h>
#include <stdlib.h>

int main() {
	void *p = NULL;
	int cnt = 0;
	double t;
	while ((p = malloc(100 * 1024 * 1024 ))) {
		cnt++;
	
	}
	free(NULL);
	printf("������%d00MB��С�Ŀռ�\n", cnt);
	return 0;
}