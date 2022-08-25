#include <stdio.h>

void insertionSort(int a[], int n);

int main(void) {
	int a[] = { 3,6,7,11,12,8,5,2 };
	int n = sizeof(a) / sizeof(int);	// 32 / 4 = 8

	insertionSort(a, n);	// a의 주소가 넘어감
	printf("삽입 정렬: ");
	for (int i = 0; i < n; i++) {
		printf("%4d ", a[i]);
	}
	printf("\n");

	return 0;
}

void insertionSort(int a[], int n) {
	// sizeof(a) / sizeof(int);	// 4 / 4
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (key < a[j]) a[j + 1] = a[j];
			else break;
		}
		a[j + 1] = key;
	}
}