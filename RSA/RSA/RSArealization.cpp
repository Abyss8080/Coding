#include<stdio.h>
#include<stdlib.h>
#include "mod.h"
#pragma warning(disable:4996)

//π´π≤√‹‘ø(E,N),√ÿ√‹√‹‘øD
int main() {
	int choice = 0;
	create_keys();
	printf("Welcome to CodeED System!\n");
	while(1) 
	{
		printf("\nPlease choose function:\n1.Encrypt\n2.Decode\n3.Quit System\n");
		printf("Your choice:");
		scanf("%d", &choice);
		if (choice == 1)
			Encrypt();
		else if (choice == 2)
			Decode();
		else if (choice == 3)
			break;
		else continue;
	}
	return 0;
}
