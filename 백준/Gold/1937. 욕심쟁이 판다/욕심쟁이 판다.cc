#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int map[501][501];
int eat[501][501];
int result = 0;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int dfs(int x, int y) {

	if (eat[x][y] != 0) {
		return eat[x][y];
	}

	eat[x][y] = 1;

	//cout << x << " " << y << " " << cur_count << endl;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (map[x][y] < map[nx][ny]) {
				eat[x][y] = max(eat[x][y], dfs(nx, ny) + 1);
			}
		}
	}
	return eat[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result = max(result, dfs(i, j));
		}
	}

	cout << result;

	return 0;
}