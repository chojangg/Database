#include <stdio.h>
void SellSort(int a[], int n) {
    int i, j, key, t;

    for (t = n / 2; t >= 1; t = t / 2) {
        for (i = 1; i < n; i++) {
            key = a[i];
            for (j = i - t; j >= 0; j -= t) {
                if (key < a[j]) a[j + t] = a[j];
                else break;
            }
            a[j + t] = key;
        }
    }
}

int main(void) {
    int a[] = { 7,12,6,11,3,8,5,2 };
    int n = sizeof(a) / sizeof(int); // 32 / 4 = 8

    SellSort(a, n);   //a를 포인터 변수로 사용할 수 없다.
    printf("쉘 정렬");

    for (int i = 1; i < n; i++) {
        printf("%4d", a[i]);
        //key = a[i];
    }
    printf("\n");

    return 0;
}
