//8방향(우,우하,하,좌하,좌,좌상,상,우상) 중 한 방향으로 이동 가능
//0은 벽, 1은 이동 가능한 경로

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 20
#define C 30
int cnt = 0;
int chk = 0;

//초기는 모두 0으로 벽임
int maze[R][C] = { 0 };

enum Bool { False, True };

struct direction {
	int r;
	int c;
};
struct direction move[8] = { { 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 },{ -1,0 },{ -1,1 } };

enum Bool nextCheck(int maze_r, int maze_c, int next_r, int next_c) {
	int i;

	for (i = 0; i < 8; i++) {
		if (next_r + move[i].r < 0 || next_c + move[i].c < 0 || next_r + move[i].r >= R || next_c + move[i].c >= C) continue;
		if (next_r + move[i].r == maze_r && next_c + move[i].c == maze_c)continue;
		if (maze[next_r + move[i].r][next_c + move[i].c] >= 1) return False;
	}
	return True;
}

void mazeCreateStart(int maze_r, int maze_c) {
	int dir, next_r, next_c;

	while (maze[maze_r][maze_c] < 255) { //8방향 모두 살펴 볼 때까지 반복
		do {
			dir = rand() % 8; //8방향 중 임의의 방향
		} while ((maze[maze_r][maze_c] & (1 << dir)) == 1);

		//이동 방향을 표시함. dir이 3이면 오른쪽에서 세 번째가 1이 되게 함. 000...000000100
		//8방향 모두 살펴보았다면 000...011111111 => 255
		maze[maze_r][maze_c] |= (1 << dir);
		next_r = maze_r + move[dir].r;
		next_c = maze_c + move[dir].c;

		if (next_r >= 0 && next_c >= 0 && next_r < R && next_c < C)
			if (maze[next_r][next_c] == 0 && nextCheck(maze_r, maze_c, next_r, next_c)) {
				maze[next_r][next_c] = 1;
				mazeCreateStart(next_r, next_c);
			}
	}
}

void mazeCreateEnd(int maze_r, int maze_c) {
	int dir, next_r, next_c, chk = 0;

	do {

		dir = rand() % 8; //8방향 중 임의의 방향

		next_r = maze_r + move[dir].r;
		next_c = maze_c + move[dir].c;

		if (next_r >= 0 && next_c >= 0 && next_r < R && next_c < C) {
			if (nextCheck(maze_r, maze_c, next_r, next_c)) {
				maze[next_r][next_c] = 1;
				maze_r = next_r;
				maze_c = next_c;
			}
			else break;
		}

	} while (1);

	maze[next_r][next_c] = 1;
}

void mazePrint(void) {
	int i, j;

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (maze[i][j] >= 1)printf("%2d", 1);
			else printf("%2d", 0);
		}
		printf("\n");
	}

}

int main(void) {
	int start_r, start_c;
	int end_r, end_c;

	srand((unsigned int)time(NULL));

	printf("미로 행 크기는 20, 열 크기는 30\n\n");
	printf("출발점의 행 번호(0~%d): ", R - 1);
	scanf_s("%d", &start_r);
	printf("출발점의 열 번호(0~%d): ", C - 1);
	scanf_s("%d", &start_c);

	printf("\n도착점의 행 번호(0~%d): ", R - 1);
	scanf_s("%d", &end_r);
	printf("도착점의 열 번호(0~%d): ", C - 1);
	scanf_s("%d", &end_c);

	maze[end_r][end_c] = 256;

	printf("\n");
	//출발점에서 미로 생성
	mazeCreateStart(start_r, start_c);

	//도착점에서 미로 생성
	mazeCreateEnd(end_r, end_c);

	//미로 출력
	mazePrint();
	printf("\n");

	return 0;
}