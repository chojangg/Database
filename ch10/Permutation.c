#include <stdio.h>
#define R 3

int b[R];
int cnt = 0;

void PrintPer(void) {
	int i;
	cnt++;

	for (i = 0; i < R; i++) printf("%d ", b[i]);
	printf("\n");
}

void exchange(int* p1, int* p2) {
	int temp = *p1;

	*p1 = *p2;
	*p2 = temp;
}

void Permutation(int a[], int n, int r) {
	int i;

	if (r == R) PrintPer();
	else for (i = r; i < n; i++) {
		exchange(a + r, a + i); //exchange(&a[0], &a[i]); 교환
		b[r] = a[r];
		Permutation(a, n, r + 1);
		exchange(a + r, a + i); //원위치
	}
}

int main(void) {
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	Permutation(a, n, 0);

	printf("\nn = %d, r = %d 일때, 순열 개수: %d\n", n, R, cnt);

	return 0;
}