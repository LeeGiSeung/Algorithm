#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n = 0;

char map[6][6];

int dx[2] = { 1,0 };
int dy[2] = { 0,1 };

int min_r = 1e9;
int max_r = -1e9;

void solve(int x, int y, int r) {

	if (x == n && y == n) {
		min_r = min(min_r, r);
		max_r = max(max_r, r);
		return;
	}

	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > n || ny > n) continue;
		int nr = r;
		if (map[x][y] == '-') {
			nr -= map[nx][ny] - '0';
		}
		else if (map[x][y] == '+') {
			nr += map[nx][ny] - '0';
		}
		else if (map[x][y] == '*') {
			nr *= map[nx][ny] - '0';
		}
		//연산자가 아니면 연산할 수 없으니까 그냥 이전 값 그대로 넘김
		solve(nx, ny, nr);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	solve(1, 1, map[1][1] -'0');

	cout << max_r << " " << min_r;
	
	return 0;
}