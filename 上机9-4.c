#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char weekstring[][10] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

enum week {Sun, Mon, Tue, Wed, Thu, Fri, Sat};

//int main() {
//	int d;
//	enum week today, w;
//
//	printf("���������ڣ�");
//	scanf("%d", &today);
//
//	printf("����������");
//	scanf("%d", &d);
//
//	printf("����������%s\n", weekstring[today]);
//
//	w = (enum week)((today + d) % 7);
//	printf("%d���������%s\n", d, weekstring[w]);
//
//
//	system("PAUSE");
//	return 0;
//}




int main() {
	int d, t, i;
	enum week w;
	char *today;
	today = (char *)malloc(sizeof(char) * 5);

	printf("���������ڣ�");
	scanf("%s", today);

	for (i = 0; i < 7; i++) {
		if (strcmp(today, weekstring[i] ) == 0) {
			t = i;
		}
	}


	printf("����������");
	scanf("%d", &d);

	printf("����������%s\n", weekstring[t]);

	w = (enum week)((t + d) % 7);
	printf("%d���������%s\n", d, weekstring[w]);


	system("PAUSE");
	return 0;
}