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

void delete(struct node* p) {	// 노드 소멸(재귀호출로 반복)
	if (p != NULL) {
		delete(p->llink);
		delete(p->rlink);
		printf("%c  ", p->data);
		// postOrder와 결과가 같음
		free(p);
	}
}

void preOrder(struct node* p) {	 // 전위 운행(D -> L -> R)
	if (p != NULL) {
		printf("%c  ", p->data);
		preOrder(p->llink);
		preOrder(p->rlink);
	}
}

void inOrder(struct node* p) {	// 중위 운행(L -> D -> R)
	if (p != NULL) {
		inOrder(p->llink);
		printf("%c  ", p->data);
		inOrder(p->rlink);
	}
}

void postOrder(struct node* p) {  // 후위 운행(L -> R -> D)
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

	printf("전위 운행(preOrder)  : ");
	preOrder(root); printf("\n");
	printf("중위 운행(inOrder)   : ");
	inOrder(root); printf("\n");
	printf("후위 운행(postOrder) : ");
	postOrder(root); printf("\n");
	printf("사라지는 순서        : ");

	delete(root);
	// deleteAll(root); 메모리 해제

	return 0;
}