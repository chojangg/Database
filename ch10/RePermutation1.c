#include <stdio.h>

int main(void) {
	int n = 5;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				printf("%d, %d, %d \n", i, j, k);
			}
		}
	}

	return 0;
}