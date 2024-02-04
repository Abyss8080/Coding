#include <stdio.h>
#include <string.h>

int main() {
	char word[33];
	scanf("%s", word);
	int len = strlen(word);
	if (len > 2 && ((word + len - 2) == "er" || (word + len - 2) == "ly"))
		word[len - 2] = '\0';
	else if (len > 3 && (word + len - 3) == "ing")
		word[len - 3] = '\0';
	printf("%s", word);
	return 0;
}