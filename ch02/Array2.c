#include <stdio.h>
#define SIZE 11

int main(void) {
    char a[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0' };
    int index, i;
    char value;

    printf("삭제위치 : ");
    scanf_s("%d", &index);
    
    for (i = index; i < SIZE - 1; i++) {
        a[i] = a[i + 1];
    }

    printf("삭제결과 : %s\n", a);

    return 0;
}