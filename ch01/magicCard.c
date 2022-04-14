#include <stdio.h>
#include <math.h>

enum bool{ false, true };

int main(void) {
	int n = 31, i, j, k = 1, cnt = 0;
	char answer;
	enum bool b[8] = { false };

	printf("0 ~ %d의 숫자를 생각하세요!\n", n);

	for (i = 0; i < log2(n); i++) {
		printf("\n\t%d번째 카드\n\n", i + 1);
		for (j = 0; j <= n; j++) {
			if ((j & k) == k) {
				printf("%d\t", j);
				cnt++;
				if (cnt % 4 == 0)printf("\n");
			}
		}
		printf("\n생각한 숫자가 있으면 y, 없으면 n입력: ");
		scanf_s("%c", &answer, 1); getchar();

		if (answer == 'y') b[i] = true;
		else b[i] = false;

		cnt = 0;
		k *= 2;
	}

	k = 1;
	answer = 0;
	for (i = 0; i < log2(n); i++) {
		if (b[i] == 1) answer += k;
		k *= 2;
	}

	if (answer <= n) printf("\n생각한 숫자는 %d입니다.\n\n", answer);
	else printf("\n대답에 오류가 있습니다.\n\n");

	return 0;
}