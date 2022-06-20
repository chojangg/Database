#include<stdio.h>
#include<malloc.h>

//이진트리에 사용할 노드
struct node {
	struct node* llink;
	char data;
	struct node* rlink;
};

struct node** queue;

int rear = -1, front = 0;
int nodeCnt = 0;

//노드 생성 함수
struct node* newNode(char data) {
	struct node* p;

	p = (struct node*)malloc(sizeof(struct node));
	p->llink = NULL;
	p->data = data;
	p->rlink = NULL;

	return p;
}

//이진트리 구성 함수
struct node* createBinaryTree(char a[]) {
	struct node* p;

	p = newNode(a[0]);
	p->llink = newNode(a[1]);
	p->rlink = newNode(a[2]);
	p->llink->llink = newNode(a[3]);
	p->llink->rlink = newNode(a[4]);
	p->rlink->llink = newNode(a[5]);
	p->rlink->rlink = newNode(a[6]);
	p->llink->llink->rlink = newNode(a[7]);
	p->rlink->llink->llink = newNode(a[8]);
	p->rlink->llink->llink->llink = newNode(a[9]);

	return p;
}

//큐에 노드 주소 삽입
void add(struct node* p) {
	if (rear == nodeCnt - 1) {
		printf("\nQudue is Full!");
		return;
	}
	queue[++rear] = p;
}

//큐를 사용함
struct node* delete(void) {
	if (rear < front) {
		printf("\nQudue is Empty! 운행을 완료함!!");
		return NULL;
	}
	return queue[front++];
}

//이진트리 모든 노드 소멸
void deleteAll(struct node* p) {
	if (p != NULL) {
		deleteAll(p->llink);
		deleteAll(p->rlink);
		free(p);
	}
}

void levelOrder(struct node* p) {
	printf("%c", p->data);
	add(p);
	while ((p = delete()) != NULL) {
		if (p->llink != NULL) {
			printf("->%c", p->llink->data);
			add(p->llink);
		}
		if (p->rlink != NULL) {
			printf("->%c", p->rlink->data);
			add(p->rlink);
		}
	}
}

int main(void) {
	char a[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	struct node* root;

	printf("이진 트리 구성을 완료함!");
	root = createBinaryTree(a);
	nodeCnt = sizeof(a) / sizeof(char);

	printf("\n\n선형 큐를 준비함!");
	queue = (struct node**)malloc(sizeof(struct node*) * nodeCnt);

	printf("\n\n레벨 오더 운행 결과: ");
	levelOrder(root);

	deleteAll(root);
	printf("\n\n이진 트리 소멸됨!\n");

	return 0;
}
