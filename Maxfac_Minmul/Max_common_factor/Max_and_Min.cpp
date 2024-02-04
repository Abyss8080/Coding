#pragma warning(disable:4996)
#include <stdio.h>
#include"M.h"

int main() {
	char* dividend = NULL;
	char* divider = NULL;//以字符串的方式输入限制长度
	long long int maxfactor = -1;
	char minmultiple[MAX * 2] = { 0 };
	Maxfac_Minmul(dividend, divider, &maxfactor, minmultiple);
	/*printf("\n%lld\n", maxfactor);
	int flag = 0;
	for (int t = 0; t < MAX * 2 - 4; t++)
	{
		if (!flag && minmultiple[t] == 0) {
			continue;
		}
		flag = 1;
		printf("%d", minmultiple[t]);
	}*/
	return 0;
}