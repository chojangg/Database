#include <stdio.h>
#define SIZE 6

int rear = -1, front = 0;
int cqueue[SIZE];
int cnt = 0;

int add(int data) {
    if (cnt == SIZE) {
        printf("CQueue Overflow!\n");
        return -1;
    }
    cnt++;
    cqueue[++rear % SIZE] = data; cnt++;
    return 0;
}

int delete() {
    if (cnt == 0) {
        printf("CQueue Underflow!\n");
        return -1;
    }
    cnt--;
    return cqueue[front++ % SIZE];
}

int main(void) {
    add(10);
    add(20);
    add(30);

    printf("%d \n", delete());
    printf("%d \n", delete());
    printf("%d \n", delete());
    printf("%d \n", delete());

    add(40);
    add(50);
    add(60);
    add(70);

    printf("%d \n", delete());

    return 0;
}