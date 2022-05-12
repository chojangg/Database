#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000000

int main(void) {
	int* a = (int*)malloc(sizeof(int) * SIZE);

	a[0] = 10;
	printf("%d\n", a[0]);

	free(a); // 동적할당은 사용 후, 항상 할당 해제(소멸)하여야 함

	return 0;
}