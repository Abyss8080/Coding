#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
//	char word1[3], word2[3];
//	scanf("%s %s", word1, word2);
//	printf("word1=%s\nword2=%s\n", word1, word2);
	char *word = "hello!";
	printf("%s", strrchr(word, 'l'));

	system("PAUSE");
	return 0;
}