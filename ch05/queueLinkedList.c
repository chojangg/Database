#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
struct node {
	int data;
	struct node* link;
};
struct node* front = NULL, * rear = NULL;
int cnt = 0;
int add(int item) {
	if (cnt == SIZE) {
		printf("Queue is Full!\n");
		return -1;
	}
	if (rear == NULL) {
		rear = (struct node*)malloc(sizeof(struct node));
		front = rear;
	}
	else {
		rear->link = (struct node*)malloc(sizeof(struct node));
		rear = rear->link;
	}
	rear->data = item;
	cnt++;
	return 0;
}
int delete() {
	int value;
	struct node* del = front;

	if (cnt == 0) {
		printf("Queue is Empty!\n");
		return -1;
	}
	value = front->data;
	front = front->link;
	if (front == NULL) rear = NULL;
	free(del);
	cnt--;
	return value;
}

int main(void) {
	add(10); add(20); add(30);
	printf("%d \n", delete());
	printf("%d \n", delete());
	add(80); add(90);

	return 0;
}