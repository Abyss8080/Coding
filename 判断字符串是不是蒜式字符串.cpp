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


//���ڸ�����һ��ֻ����Сд��ĸ���ַ�����������а����ַ��� "jsk" ��
//���߸��ַ����е������ַ�����ĸ�����ƶ�����λ������ַ��� "jsk" ��
//��ô���Ǿ�˵����ַ����ǡ���ʽ�ַ�������