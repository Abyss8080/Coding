#include <stdio.h>

int main()

{
	int amount = 0;
	int price = 0;

	printf("实收金额(元)：\n");
	scanf("%d", &amount);
	printf("应收金额（元):\n");
	scanf("%d", &price);

	int change = amount - price;


	if (change < 0) {
		printf("你的余额不足以支付。");
	} else {
		printf("找您%d元。\n", change);
	}

	printf("谢谢惠顾!");
	return 0;

}