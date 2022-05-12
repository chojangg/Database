#include<stdio.h>
#include<stdlib.h>

struct node {
	char data;
	struct node* link;
};

void deleteLinkedList(struct node* p) {
	if (p != NULL) {
		deleteLinkedList(p->link);
		printf("%c.", p->data);
		free(p);
	}
}

int main(void) {

	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* p;
	char input = ' ';

	head->data = input;
	head->link = NULL;
	p = head;

	printf("데이터 입력: ");
	scanf_s("%c", &input, 1);
	getchar();

	while (input != '0') {
		p->link = (struct node*)malloc(sizeof(struct node));
		p = p->link;
		p->data = input;
		p->link = NULL;
		printf("데이터 입력: ");
		scanf_s("%c", &input, 1);
		getchar();
	}

	printf("\n연결리스트 출력: ");
	p = head->link;

	while (p != NULL) {
		printf("%c", p->data);
		p = p->link;
		if (p != NULL)printf(" -> ");
	}
	printf("\n");

	printf("\n사라지는 순서: ");
	deleteLinkedList(head);
	printf("\n");

	return 0;
}