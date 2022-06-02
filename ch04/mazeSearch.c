#include <stdio.h>
#include <stdlib.h>
#define M 12
#define N 16
#define MAX M*N

enum boolean { false, true };

int top = -1;
int stack[MAX][3] = { 0, };

enum boolean push(int x, int y, int d) {
	if (top >= MAX - 1) {
		printf("stack overflow\n");
		return false;
	}
	top = top + 1;
	stack[top][0] = x;
	stack[top][1] = y;
	stack[top][2] = d;
	return true;
}

enum boolean pop(int* x, int* y, int* d) {
	if (top == -1) {
		printf("stack underflow\n");
		return false;
	}
	*x = stack[top][0];
	*y = stack[top][1];
	*d = stack[top][2];
	top = top - 1;
	return true;
}

enum boolean mazeSearch(int maze[M][N]) {
	int in_x, in_y, out_x, out_y;
	int view_x, view_y, current_x, current_y;
	int d = 0; // d는 이동할 수 있는 0~7 방향 중 하나로 0에서 출발
	//0방향은 우, 1방향은 우하, 2방향은 하, 3방향은 좌하, 4방향은 좌, 5방향은 좌상, 6방향은 상, 7방향은 우상
	int move[8][2] = { { 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 },{ -1,0 },{ -1,1 } };

	printf("출발 행: "); scanf_s("%d", &in_x);
	printf("출발 열: "); scanf_s("%d", &in_y);
	printf("도착 행: "); scanf_s("%d", &out_x);
	printf("도착 열: "); scanf_s("%d", &out_y);

	//current_x는 현재 행, current_y는 현재 열
	current_x = in_x;
	current_y = in_y;
	while (1) {
		while (d < 8) {
			//view_x는 살펴보는 행, view_y는 살펴보는 열. 즉 다음 방향
			view_x = current_x + move[d][0];
			view_y = current_y + move[d][1];
			//(view_x, view_y)쪽으로 전진할 수 있다면. 즉 배열 범위내에 있고 1이 들어있으면
			if (view_x >= 0 && view_x < M && view_y >= 0 && view_y < N && maze[view_x][view_y] == 1) {
				maze[current_x][current_y] = 9; // 현재 위치를 미로로 표시
				//스택에 현재위치와 다음 방향을 push하고 돌아오는 값이 false이면 미로가 없으므로 false 리턴
				if (!push(current_x, current_y, d + 1)) return false;
				//push가 잘 되었으면 전진. 즉 다음 방향(전진할 수 있는 좌표)이 현재 위치가 됨
				current_x = view_x;
				current_y = view_y;
				//다음 위치로 전진하였다면 0방향부터 살펴봄
				d = 0;
				//현재 위치가 출구에 도달하였다면 미로 표시하고 true를 리턴
				if (current_x == out_x && current_y == out_y) {
					maze[current_x][current_y] = 9;
					return true;
				}
			}
			else d++; //전진할 수 없으면 다음 방향으로
		}
		//d가 8이면 더이상 전진할 방향이 없으므로
		maze[current_x][current_y] = 2; // 미로가 아님을 표시하고
		//스택에서 직전의 위치 좌표와 방향을 받아옴. 스택이 비어있다면 false가 리턴되고 main()으로 false를 리턴함
		if (pop(&current_x, &current_y, &d) == false) return false;
	}
}

int main(void) {
	// 0은 벽, 1은 갈 수 있는 통로
	int maze[M][N] = { {1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0},
			{0,1,1,0,0,0,1,0,0,1,0,0,1,0,0,1},
			{1,0,0,1,1,1,1,1,1,0,0,0,1,0,0,1},
			{1,0,0,0,0,1,0,0,0,0,0,1,1,1,1,0},
			{1,1,0,0,0,0,1,0,1,1,1,0,0,0,1,0},
			{0,0,1,0,0,1,0,1,0,0,1,1,0,0,0,1},
			{0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
			{1,0,0,1,0,1,1,1,1,1,0,1,1,0,0,0},
			{1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0},
			{0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,1},
			{1,1,0,0,0,1,1,1,1,1,0,0,1,1,0,1},
			{1,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1} };
	int i, j;

	if (mazeSearch(maze) == false) printf("출구까지 미로 없음!!\n\n");
	else {
		printf("\n미로 찾기 완료\n");
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++)
				if (maze[i][j] == 9) printf("* "); // 미로이면  * 출력
				else printf("%d ", maze[i][j] == 0 ? 0 : 1); //미로 아니면 초기 데이터 출력
			printf("\n");
		}
	}
	printf("\n");

	return 0;
}
