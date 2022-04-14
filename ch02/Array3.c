#include <stdio.h>

int main(void) {
	int i, j, b[5][3];
	int a[3][5] = { {5,41,24,6,10},
					{50,33,20,15,11},
					{ 7,17,35,21,16} };

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			b[i][j] = a[i][j];
		}
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			printf("%2d ", b[i][j]);
		}
		printf("\n");
	}

	return 0;
}