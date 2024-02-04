#include <stdio.h>
#define MAX 200*101+1

int main() {
	char sentence[MAX];
	int i, max, min, maxi, mini, count;
	i = max = maxi = mini = count = 0;
	min = MAX;
	int hasempty = 1;
	gets(sentence);
	while (sentence[i] != '\0') {
		if ((sentence[i] == ' ' || sentence[i] == ',') && hasempty == 0) {
			hasempty = 1;
			if (count > max) {
				max = count;
				maxi = i - count;
			}
			if (count < min) {
				min = count;
				mini = i - count;
			}
			count = 0;
		} else if (sentence[i] != ' ' || sentence[i] != ',') {
			count++;
			if (hasempty == 1)
				hasempty = 0;
		}
		i++;
	}
	if (max == 0 && min == MAX) {
		max = min = count;
		maxi = mini = 0;
	}

	for (i = maxi; i < maxi + max; i++) {
		printf("%c", sentence[i]);
	}
	printf("\n");
	for (i = mini; i < mini + min; i++) {
		printf("%c", sentence[i]);
	}

	return 0;
}