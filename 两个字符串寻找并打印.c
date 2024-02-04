#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

typedef struct node {
	char substring[MAX];
	struct node *next;
} Sub;

void InputString(char str[]);
Sub *FindString(char str1[], char str2[]);
void PrintsubStr(Sub **phead);


int main() {
	char str1[MAX] = {0};
	char str2[MAX] = {0};
	Sub *head, *p;

	InputString(str1);
	InputString(str2);

	head = FindString(str1, str2);

	if (head->substring[0] != '\0')
		PrintsubStr(&head);
	else
		printf("两字符串没有公共字串。\n");

	do {
		p = head->next;
		free(head);
		head = p;
	} while (head == NULL);

	system("PAUSE");
	return 0;
}


void InputString(char str[]) {
	printf("Input str up to 100 characters:\n");
	gets(str);
}

Sub *FindString(char str1[], char str2[]) {
	Sub *pnew, *phead, *p;
	char a[MAX] = {0};
	int i = 0, j = 0;
	int m = 0, n = 0;
	int k = 0, q = 0;

	pnew = (Sub *)malloc(sizeof(Sub));
	pnew->substring[0] = '\0' ;
	pnew->next = NULL;
	p = pnew;
	phead = pnew;

	while (str1[i] != '\0') {
		while (str2[j] != '\0') {
			m = i;
			n = j;
			while (str1[i] == str2[j] && str1[i] != ' ') {
				a[k] = str1[i];
				k++;
				i++;
				j++;
			}

			if (k >= 3) {
				strcat(p->substring, a);
				pnew = (Sub *)malloc(sizeof(Sub));
				pnew->substring[0] = '\0';
				pnew->next = NULL;
				p->next = pnew;
				p = p->next;
				n += k - 1;
				m += k - 1;
			} else {
				for (q = 0; a[q] != '\0'; q++) {
					a[q] = 0;
				}
			}
			k = 0;
			i = m;
			j = n;
			j++;
		}
		j = 0;
		i++;
	}
	return phead;
}




void PrintsubStr(Sub **phead) {
	Sub **p;
	p = phead;
	printf("公共字串：");
	while ((*p)->next != NULL) {
		printf(" %s,", (*p)->substring);
		*p = (*p)->next;
	}
}





