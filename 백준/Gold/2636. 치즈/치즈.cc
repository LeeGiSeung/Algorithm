#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int count_cheese = 0;
int cheese[101][101];
int copy_cheese[101][101];

bool cheese_visit[101][101];

bool air_visit[101][101];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int n, m;

void find_air() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			//0,0 부터 시작해서 cheese의 값이 0인지 확인하고 만약 값이 0이라면 외부 노출된 공기로 생각한다.
			if (0 <= nx && nx < n && 0 <= ny && ny < m && cheese_visit[nx][ny] == false && cheese[nx][ny] == 0) {
				cheese_visit[nx][ny] = true;
				air_visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

void solve(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && air_visit[nx][ny] == true && cheese[nx][ny] == 0) {
			//4 방면중 바깥에 노출된 공기가 있을경우 현재 위치 0으로 변경
			copy_cheese[x][y] = 0;
			break;
		}
	}
	return;

}

void cheese_copy(int x[101][101], int y[101][101]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			y[i][j] = x[i][j];
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	// 치즈가 감싸고 있는 공간은 공기와 맞닿아 있기 때문에 한시간이 지나면 사라진다. 치즈가 사라지면 그쪽으로 공기가 침투함
	// 공간으로만 구성돼 있는 공간을 찾고 한번 bfs를 돌고 공기 공간을 업데이트 해줘야 한다.

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cheese[i][j];
		}
	}

	int result = 0;
	int flag = 0;
	int ch = 0;

	while (true) {
		flag = 0;
		memset(cheese_visit, false, sizeof(cheese_visit));
		find_air();
		cheese_copy(cheese, copy_cheese);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(cheese[i][j] == 1) {
					count_cheese++;
					flag = 1;
					solve(i, j);
				}
			}
		}

		//cout << result << "가 지났을때 치즈 갯수는 " << count_cheese << " " << "\n";

		if (flag == 0) {
			break;
		}

		cheese_copy(copy_cheese, cheese);
		ch = count_cheese;
		count_cheese = 0;
		result++;
	}

	cout << result << "\n";
	cout << ch;

	return 0;
}