#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
//	char t[29] = "aby";
	char *t;
	t = (char *)malloc(20 * sizeof(char));
	t = "you ";
	printf("%d", strlen(t));
//	strcat(t, "you");
//	gets(t);
//	scanf("%s", t);
//	printf("%c\n", t[3]);
//	puts(t);

	free(t);
	system("PAUSE");
	return 0;
}


