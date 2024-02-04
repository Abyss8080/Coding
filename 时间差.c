#include <stdio.h>

int main() {
	int hour1, minute1;
	int hour2, minute2;
	scanf("%d %d", &hour1, &minute1);
	scanf("%d %d", &hour2, &minute2);
	int t1 = hour1 * 60 + minute1;
	int t2 = hour2 * 60 + minute2;

	printf("²î%dĞ¡Ê±%d·ÖÖÓ¡£", (t1 - t2) / 60, (t1 - t2) % 60);
}