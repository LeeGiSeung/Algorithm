#include <iostream>
#include <vector>

using namespace std;

// s는 속력, d는 이동 방향, z는 크기이다

struct SHARK {
	int Speed = 0;
	int Direction = 0;
	int size = 0;
};

int r, c, m;
SHARK null_map[101][101];
SHARK map[101][101];
SHARK mapCopy[101][101];

int result = 0;

void copy_map(SHARK x[101][101], SHARK y[101][101]) {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			y[i][j] = x[i][j];
		}
	}
}

void Hunting(int y) {
	//낚시장 깊이를 넘지 않을 때 까지 반복
	int x = 1;
	while (x <= r) {
		//만약 그 칸에 상어가 있으면
		if (map[x][y].size > 0) {
			//죽이기 전에 무게 추가
			result += map[x][y].size;
			//상어 죽임
			map[x][y].size = 0;
			map[x][y].Direction = 0;
			map[x][y].Speed = 0;
			break;
		}
		else {
			x++;
		}
	}
}
//d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽
//d가 1부터 시작이라서 그냥 5개로 만들었음
int dx[5] = { 0,		-1,1,0,0 };
int dy[5] = { 0,		0,0,1,-1 };

void Swiming12(int i, int j, int d) {
	int x = i;
	int y = j;
	int direction = d;
	int speed = map[i][j].Speed;

	//상어가 벽에 닿았는지 유무
	int flag = 1;

	//상어가 총 이동한 거리
	int move = 0;

	int nx = x;

	while (move < speed) {

		if (1 <= nx + dx[direction] && nx + dx[direction] <= r) {
			nx = nx + dx[direction];
			move++;
		}
		else {
			//벽에 닿았을 경우 break;
			flag = 0;
		}
		//벽에 닿았을 경우
		if (flag == 0) {
			if (direction == 1) {
				direction = 2;
			}
			else {
				direction = 1;
			}
			flag = 1;
		}

	}

	//움직일려는 상어의 크기가 기존에 있던 상어의 크기보다 크거나, 이동할려는 자리에 상어가 없으면 이동 가능함
	if (map[x][y].size > mapCopy[nx][y].size || mapCopy[nx][y].size == 0) {
		mapCopy[nx][y] = map[x][y];
		mapCopy[nx][y].Direction = direction;
		//cout << "이동한 상어 위치" << nx << " " << y << endl;
	}

	// 만약 움직일 위치의 상어가 나보다 이미 크다면 현재 상어는 죽음 크기가 같은 상어는 없다고 문제에 나와있음
	else {
		map[x][y].size = 0;
		map[x][y].Direction = 0;
		map[x][y].Speed = 0;
		//cout << "뒤진 위치" << nx << " " << y << endl;
		//cout << "뒤짐" << endl;
	}

}

void Swiming34(int i, int j, int d) {
	int x = i;
	int y = j;
	int direction = d;
	int speed = map[i][j].Speed;

	//상어가 벽에 닿았는지 유무
	int flag = 1;

	//상어가 총 이동한 거리
	int move = 0;

	int ny = y;

	while (move < speed) {

		if (1 <= ny + dy[direction] && ny + dy[direction] <= c) {
			ny = ny + dy[direction];
			move++;
		}
		else {
			//벽에 닿았을 경우 break;
			flag = 0;
		}
		//벽에 닿았을 경우
		if (flag == 0) {
			if (direction == 3) {
				direction = 4;
			}
			else {
				direction = 3;
			}
			flag = 1;
		}
	}

	//움직일려는 상어의 크기가 기존에 있던 상어의 크기보다 크거나, 이동할려는 자리에 상어가 없으면 이동 가능함
	if (map[x][y].size > mapCopy[x][ny].size || mapCopy[x][ny].size == 0) {
		mapCopy[x][ny] = map[x][y];
		mapCopy[x][ny].Direction = direction;
		//cout << "이동한 상어 위치" << x << " " << ny << endl;
	}

	// 만약 움직일 위치의 상어가 나보다 이미 크다면 현재 상어는 죽음 크기가 같은 상어는 없다고 문제에 나와있음
	else {
		map[x][y].size = 0;
		map[x][y].Direction = 0;
		map[x][y].Speed = 0;
		//cout << "뒤진 위치" << x << " " << ny << endl;
		//cout << "뒤짐" << endl;
	}
}

void Start(int i, int j) {
	int size = map[i][j].size;
	int direction = map[i][j].Direction;
	int speed = map[i][j].Speed;

	if (direction == 1 || direction == 2) {
		Swiming12(i, j, direction);
	}
	else if (direction == 3 || direction == 4) {
		Swiming34(i, j, direction);
	}
}

void Move() {

	//낚시장 검사
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			//만약 상어가 있으면
			if (map[i][j].size > 0) {
				//cout << "원래 상어 위치" << i << " " << j << endl;
				//이동 시작
				Start(i, j);
				//cout << endl;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> m;

	for (int i = 0; i < m; i++) {
		int x, y, s, d, z;
		//r, c, s, d, z
		cin >> x >> y >> s >> d >> z;
		map[x][y] = { s,d,z };
	}

	//낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다. 다음은 1초 동안 일어나는 일이며, 아래 적힌 순서대로 일어난다. 낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.


	for (int i = 1; i <= c; i++) {
		copy_map(null_map, mapCopy);
		//cout << "낚시꾼 위치" << i << endl;
		//1. 낚시왕이 오른쪽으로 한 칸 이동한다.
		//2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
		Hunting(i);

		//3.상어가 이동한다.
		Move();

		//mapCopy를 map에 복사
		copy_map(mapCopy, map);
	}

	cout << result;

	return 0;
}
