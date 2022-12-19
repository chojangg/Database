#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//미로 크기, row(>=3)는 행, col(>=3)은 열 크기
int row, col;

//미로를 재귀적 귀로 호출 방법으로 만들어 나감
void mazeCreating(char** mazeMark, int i, int j) {
	int view_i, view_j, dir;
	int move[4][2] = { {-2,0},{2,0},{0,-2},{0,2} };//상하좌우

	while (mazeMark[i][j] < 15) { //상하좌우 모두 살펴 볼 때까지 반복
		do {
			dir = rand() % 4; //4방향 중 임의의 방향
		} while ((mazeMark[i][j] & (1 << dir)) == 1); //dir이 살펴본 방향이면 dir 다시 구함

		//이동 방향을 표시함. dir이 3이면 오른쪽에서 세 번째가 1이 되게 함. 00000100
		//4방향 모두 살펴보았다면 00001111 => 15
		mazeMark[i][j] |= (1 << dir);

		//이동할 방의 좌표를 구함
		view_i = i + move[dir][0];
		view_j = j + move[dir][1];

		//이동할 방의 좌표가 미로 행열 범위내에 있고
		if (view_i >= 1 && view_i <= row - 2 && view_j >= 1 && view_j <= col - 2) {
			//탐색을 하지 않았다면
			if (mazeMark[view_i][view_j] == 0) {
				//이동 방향의 벽을 제거
				switch (dir) {
				case 0:mazeMark[i - 1][j] = 1; break;
				case 1:mazeMark[i + 1][j] = 1; break;
				case 2:mazeMark[i][j - 1] = 1; break;
				case 3:mazeMark[i][j + 1] = 1;
				}
				//이동한 방에서 같은 과정을 되풀이함
				mazeCreating(mazeMark, view_i, view_j);
			}
		}

	}

}

int main(void) {
	int i, j;
	char** mazeMark;

	do {
		printf("미로의 행 크기(3 이상의 홀수): ");
		scanf_s("%d", &row);
		if (row % 2 == 1)break;
		printf("\n다시 입력하세요.");
	} while (1);

	do {
		printf("\n미로의 열 크기(3 이상의 홀수): ");
		scanf_s("%d", &col);
		if (col % 2 == 1)break;
		printf("\n다시 입력하세요.");
	} while (1);

	//2차원 배열처럼 사용할 mazeMark 준비
	mazeMark = (char**)malloc(sizeof(char*) * row);
	for (i = 0; i < row; i++) mazeMark[i] = (char*)malloc(sizeof(char) * col);

	//모든 방들을 0(벽)으로 채움
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			mazeMark[i][j] = 0;
		}
	}

	srand((unsigned int)time(NULL));

	//출발점을 임의로 정함
	i = (int)rand() % (row - 1);
	j = (int)rand() % (col - 1);

	//출발점 행열이 짝수이면 홀수로 만듦 
	if (i % 2 == 0)i++;
	if (j % 2 == 0)j++;

	//재귀적 귀로 방법 호출
	mazeCreating(mazeMark, i, j);

	//미로를 출력함 
	printf("\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (mazeMark[i][j] == 0) printf("▦");
			else printf("　");
		}
		printf("\n");
	}

	return 0;

}