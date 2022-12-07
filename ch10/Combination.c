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

void Combination(int a[], int n, int r, int ii) {
	int i;

	if (r >= R) PrintB();
	else	for (i = ii + 1; i < n; i++) {
		b[r] = a[i];
		Combination(a, n, r + 1, i);
	}
}

int main(void) {
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	printf("\n");
	for (int i = 0; i < n; i++)printf("%d  ", a[i]);
	printf("에서 %d개 조합은\n\n", R);

	Combination(a, n, 0, -1);

	printf("\n조합 개수 : %d\n", cnt);

	return 0;
}