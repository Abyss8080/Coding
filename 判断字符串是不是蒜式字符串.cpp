#include <stdio.h>
#include <string.h>
#define maxn 100010
char a[maxn];

int main() {
	scanf("%s", a);
	int len = strlen(a);
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < len; j++) {
			if (a[j] != 'z') {
				a[j] = a[j] + 1;
			} else {
				a[j] = 'a';
			}
		}
		for (int j = 0; j < len - 2; j++) {
			if (a[j] == 'j' && a[j + 1] == 's' && a[j + 2] == 'k') {
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}


//对于给定的一个只包含小写字母的字符串，如果其中包含字符串 "jsk" ，
//或者该字符串中的所有字符在字母表中移动若干位后包含字符串 "jsk" ，
//那么我们就说这个字符串是“蒜式字符串”。