#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	//尾数
	unsigned char bit0: 1;
	unsigned char bit1: 1;
	unsigned char bit2: 1;
	unsigned char bit3: 1;
	unsigned char bit4: 1;
	unsigned char bit5: 1;
	unsigned char bit6: 1;
	unsigned char bit7: 1;
	unsigned char bit8: 1;
	unsigned char bit9: 1;
	unsigned char bit10: 1;
	unsigned char bit11: 1;
	unsigned char bit12: 1;
	unsigned char bit13: 1;
	unsigned char bit14: 1;
	unsigned char bit15: 1;
	unsigned char bit16: 1;
	unsigned char bit17: 1;
	unsigned char bit18: 1;
	unsigned char bit19: 1;
	unsigned char bit20: 1;
	unsigned char bit21: 1;
	unsigned char bit22: 1;
	//指数
	unsigned char bit23: 1;
	unsigned char bit24: 1;
	unsigned char bit25: 1;
	unsigned char bit26: 1;
	unsigned char bit27: 1;
	unsigned char bit28: 1;
	unsigned char bit29: 1;
	unsigned char bit30: 1;
	//符号位
	unsigned char bit31: 1;
	//reverse printf
} Node;

union {
	unsigned int number: 32;
	Node bits;
} ans;

int main() {
	float fNum;
	unsigned int *pNum;
	//32:1-8-23
	pNum = (unsigned int *)&fNum;
	scanf("%lf", &fNum);
	printf("%p\n", *pNum);
	printf("%x\n", *pNum);
	ans.number = *pNum;
	printf("符号位：");
	printf("%u \n", ans.bits.bit31);
	printf("指数位：");
	printf("%u ", ans.bits.bit30);
	printf("%u ", ans.bits.bit29);
	printf("%u ", ans.bits.bit28);
	printf("%u ", ans.bits.bit27);
	printf("%u ", ans.bits.bit26);
	printf("%u ", ans.bits.bit25);
	printf("%u ", ans.bits.bit24);
	printf("%u \n", ans.bits.bit23);
	printf("尾数位：");
	printf("%u ", ans.bits.bit22);
	printf("%u ", ans.bits.bit21);
	printf("%u ", ans.bits.bit20);
	printf("%u ", ans.bits.bit19);
	printf("%u ", ans.bits.bit18);
	printf("%u ", ans.bits.bit17);
	printf("%u ", ans.bits.bit16);
	printf("%u ", ans.bits.bit15);
	printf("%u ", ans.bits.bit14);
	printf("%u ", ans.bits.bit13);
	printf("%u ", ans.bits.bit12);
	printf("%u ", ans.bits.bit11);
	printf("%u ", ans.bits.bit10);
	printf("%u ", ans.bits.bit9);
	printf("%u ", ans.bits.bit8);
	printf("%u ", ans.bits.bit7);
	printf("%u ", ans.bits.bit6);
	printf("%u ", ans.bits.bit5);
	printf("%u ", ans.bits.bit4);
	printf("%u ", ans.bits.bit3);
	printf("%u ", ans.bits.bit2);
	printf("%u ", ans.bits.bit1);
	printf("%u \n", ans.bits.bit0);



	system("PAUSE");
	return 0;
}