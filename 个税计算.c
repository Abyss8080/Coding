#include <stdio.h>
int main()

{
	double tax, rate, income;
	int t;
	printf("请输入您的应纳税所得额：");
	scanf("%lf", &income);
	switch (income <= 36000) {
		case 1:
			rate = 0.03;
			t = 0;
			break;
		case 0:
			switch (income <= 144000) {
				case 1:
					rate = 0.10;
					t = 2520;
					break;
				case 0:
					switch (income <= 300000) {
						case 1:
							rate = 0.20;
							t = 16920;
							break;
						case 0:
							switch (income <= 420000) {
								case 1:
									rate = 0.25;
									t = 31920;
									break;
								case 0:
									switch (income <= 660000) {
										case 1:
											rate = 0.30;
											t = 52920;
											break;
										case 0:
											switch (income <= 960000) {
												case 1:
													rate = 0.35;
													t = 85920;
													break;
												case 0:
													rate = 0.45;
													t = 181920;
													break;
											}
									}
							}
					}
			}
	}


	tax = income * rate - t;
	printf("您需纳税%.2lf元。", tax);
	return 0 ;

}