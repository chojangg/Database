#include <stdio.h>

int main(void) {
	struct node {
		char data;
		struct node* link;
	}a, b, c, * p;

	p = &a;
	a.data = 'A';
	a.link = &b;
	b.data = 'B';
	b.link = &c;
	c.data = 'C';
	c.link = NULL;
	printf("%c",c.link);
}