#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* llink;
	char data;
	struct node* rlink;
};

struct node* create(char data) {
	struct node* p;
	p = (struct node*)malloc(sizeof(struct node));

	p->llink = NULL;
	p->data = data;
	p->rlink = NULL;
	return p;
}

void delete(struct node* p) {	// ��� �Ҹ�(���ȣ��� �ݺ�)
	if (p != NULL) {
		delete(p->llink);
		delete(p->rlink);
		printf("%c  ", p->data);
		// postOrder�� ����� ����
		free(p);
	}
}

void preOrder(struct node* p) {	 // ���� ����(D -> L -> R)
	if (p != NULL) {
		printf("%c  ", p->data);
		preOrder(p->llink);
		preOrder(p->rlink);
	}
}

void inOrder(struct node* p) {	// ���� ����(L -> D -> R)
	if (p != NULL) {
		inOrder(p->llink);
		printf("%c  ", p->data);
		inOrder(p->rlink);
	}
}

void postOrder(struct node* p) {  // ���� ����(L -> R -> D)
	if (p != NULL) {
		postOrder(p->llink);
		postOrder(p->rlink);
		printf("%c  ", p->data);
	}
}

int main(void) {
	struct node* root = create('A');
	root->llink = create('B');	
	root->rlink = create('C');
	root->llink->llink = create('D');
	root->llink->rlink = create('E');
	root->rlink->llink = create('F');
	root->rlink->rlink = create('G');
	root->llink->rlink->llink = create('H');

	printf("���� ����(preOrder)  : ");
	preOrder(root); printf("\n");
	printf("���� ����(inOrder)   : ");
	inOrder(root); printf("\n");
	printf("���� ����(postOrder) : ");
	postOrder(root); printf("\n");
	printf("������� ����        : ");

	delete(root);
	// deleteAll(root); �޸� ����

	return 0;
}