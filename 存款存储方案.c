#include <stdio.h>

int main() {
	int deposit, i;
	double ta = 0.0204,
	       tb = 0.0197,
	       tc = 0.0206,
	       td = 0.0175,
	       max1,
	       output1;
	double Ta = 0.0268,
	       Tb = 0.0312,
	       Tc = 0.0254,
	       Td = 0.0278,
	       max3,
	       output3;

//	char a = "大型商业银行",
//	     b = "股份商业银行",
//	     c = "城商行",
//	     d = "外资银行";
	printf("请输入您欲存款的金额：");
	scanf("%d", &deposit);

	if (ta > tb) {
		ta = ta;
	} else {
		ta = tb;
	}
	if (tc > td) {
		tc = tc;
	} else {
		tc = td;
	}
	if (ta > tc) {
		ta = ta;
	} else {
		ta = tc;
	}
	max1 = ta;
	for (i = 1; i <= 3; i++) {
		output1 = deposit * (1 + max1);
		deposit = output1;

	}


	if (Ta > Tb) {
		Ta = Ta;
	} else {
		Ta = Tb;
	}
	if (Tc > Td) {
		Tc = Tc;
	} else {
		Tc = Td;
	}
	if (Ta > Tc) {
		Ta = Ta;
	} else {
		Ta = Tc;
	}
	max3 = Ta;
	output3 = deposit * (max3 + 1);
	printf("max1=%lf,max3=%lf\n", max1, max3);
	printf("output1=%.2lf,output3=%.2lf\n", output1, output3);
	if (output1 > output3) {
		printf("每年存一次存三年合算。");

	} else if (output1 == output3) {
		printf("两种方法一样合算。");
	} else if (output1 < output3) {
		printf("一次存三年合算。");

	}


	return 0;


}