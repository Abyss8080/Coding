#include <stdio.h>

int main()

{
	int amount = 0;
	int price = 0;

	printf("ʵ�ս��(Ԫ)��\n");
	scanf("%d", &amount);
	printf("Ӧ�ս�Ԫ):\n");
	scanf("%d", &price);

	int change = amount - price;


	if (change < 0) {
		printf("���������֧����");
	} else {
		printf("����%dԪ��\n", change);
	}

	printf("лл�ݹ�!");
	return 0;

}