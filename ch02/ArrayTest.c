#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, j;
	int a[] = { 'P','r','a','c','t','i','c','e',' ','m','a','k','e','s',' ','p','e','r','f','e','c','t','.','\n' };
	int	b[5][10] = { {' ',' ', ' ',' ','A','\n'},
					 {' ',' ',' ','A','B','C','\n'},
					 {' ',' ','A','B','C','D','E','\n',},
					 {' ','A','B','C','D','E','F','G','\n',},
					 {'A','B','C','D','E','F','G','H','I','\n',} };

	// 1번
	for (i = 0; i < 23; i++) {
		printf("%c", a[i]);
	}
	printf("\n");

	// 2번
	for (i = 23; i >= 0; i--) {
		printf("%c", a[i]);
	}
	printf("\n");
	printf("\n");
	// 3번
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 10; j++) {
			if (b[i][j] == ' ') continue;
			printf("%c", b[i][j]);
		}
	}
	printf("\n");
	// 4번
	for (i = 0; i < 5; i++) {
		printf("   %c\n", b[i][4]);
	}
	printf("\n");
	// 5번
	for (i = 0; i <= 8; i++) {
		for (j = 4; j >= 0; j--) {
			if (b[j][i] != 0) {
				printf("%c", b[j][i]);
			}
		}
		printf("\n");
	}

	return 0;
}