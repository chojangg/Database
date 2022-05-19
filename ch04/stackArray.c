#include<stdio.h>
#define MAX 6
int top = -1;
int stack[MAX] = { 0, };

int PUSH(int data) {
	if (top == MAX - 1) {
		printf("stack overflow\n");
		return -1;
	}
	stack[++top] = data;
	return 0;
}

int POP() {
	if (top == -1) {
		printf("stack underflow\n");
		return -1;
	}
	return stack[top--];
}

int main(void) {
	PUSH(10); PUSH(20); PUSH(30); PUSH(40); PUSH(50); PUSH(60); PUSH(70);
	printf("POP:%d,", POP()); printf("POP:%d,", POP()); printf("POP:%d,", POP());
	PUSH(80);
	printf("POP:%d,", POP()); printf("POP:%d,", POP()); printf("POP:%d,", POP());
	printf("POP:%d,", POP()); printf("POP:%d,", POP());
	return 0;
}