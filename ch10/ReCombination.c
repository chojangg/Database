#include <stdio.h>
#define R 3

int b[R];
int cnt = 0;

void PrintB() {
	int i;

	cnt++;
	for (i = 0; i < R; i++) printf("%d  ", b[i]);
	printf("\n");
}

void reCombination(int a[], int n, int r, int ii) {
	int i;

	if (r == R) PrintB();
	else	for (i = ii; i < n; i++) {
		b[r] = a[i];
		reCombination(a, n, r + 1, i);
	}
}

int main(void) {
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	printf("\n");
	for (int i = 0; i < n; i++)printf("%d  ", a[i]);
	printf("에서 %d개 중복 조합은\n\n", R);

	reCombination(a, n, 0, 0);

	printf("\n중복 조합 개수 : %d\n", cnt);

	return 0;
}