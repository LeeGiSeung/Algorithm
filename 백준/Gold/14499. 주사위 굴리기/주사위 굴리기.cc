#include <stdio.h>

int N, M, x, y, K, command;
int map[20][20];
int dice[6];

// 1번 단계
int check() {
	switch (command) {
	case 1:
		if (y == M - 1)
			return 0;
		break;
	case 2:
		if (y == 0)
			return 0;
		break;
	case 3:
		if (x == 0)
			return 0;
		break;
	case 4:
		if (x == N - 1)
			return 0;
		break;
	}
	return 1;
}

// 2번 단계
void dice_rolling() {
	int temp = 0;
	temp = dice[0];
	switch (command) {
	case 1:
		y++;
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
		break;
	case 2:
		y--;
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
		break;
	case 3:
		x--;
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;
		break;
	case 4:
		x++;
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
		break;
	}
}

// 3번 단계
void fill_value() {
	if (map[x][y] == 0)
		map[x][y] = dice[5];
	else {
		dice[5] = map[x][y];
		map[x][y] = 0;
	}
}

// 4번 단계
void print() {
	printf("%d\n", dice[0]);
}

int main() {

	scanf("%d%d%d%d%d", &N, &M, &x, &y, &K);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	for (int i = 0; i < K; i++) {
		scanf("%d", &command);
		if (!check())
			continue;
		dice_rolling();
		fill_value();
		print();
	}

	return 0;
}