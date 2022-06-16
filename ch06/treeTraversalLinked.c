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

void delete(struct node* p) {
	if (p != NULL) {
		delete(p->llink);
		delete(p->rlink);
		free(p);
	}
}

void preOrder(struct node* p) {
	if (p != NULL) {
		printf("%c  ", p->data);
		preOrder(p->llink);
		preOrder(p->rlink);
	}
}

void inOrder(struct node* p) {
	if (p != NULL) {
		inOrder(p->llink);
		printf("%c  ", p->data);
		inOrder(p->rlink);
	}
}

void postOrder(struct node* p) {
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

	printf("傈困 款青(preOrder)  : ");
	preOrder(root); printf("\n");
	printf("吝困 款青(inOrder)   : ");
	inOrder(root); printf("\n");
	printf("饶困 款青(postOrder) : ");
	postOrder(root); printf("\n");

	delete(root);

	return 0;
}