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
	/*转换成大写*/

	if (isupper(ch))
		ch = tolower(ch);
	putchar(ch);
	/*转换成小写*/

	return 0;

}