#include <stdio.h>
#include <ctype.h>

int main(void) {
	char ch;
	printf("Enter a text:\n");
	ch = getchar();
//	ch = getch();
//	ch = getche();



//	if (islower(ch))
//		ch = toupper(ch);
//	putchar(ch);
	/*ת���ɴ�д*/

	if (isupper(ch))
		ch = tolower(ch);
	putchar(ch);
	/*ת����Сд*/

	return 0;

}