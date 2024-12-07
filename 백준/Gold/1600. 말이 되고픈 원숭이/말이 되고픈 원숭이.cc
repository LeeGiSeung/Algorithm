#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int k, n, m;
int map[201][201];
int result = -1;
struct DATA {
	int x;
	int y;
	int ti;
	int horsemoving;
};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[201][201][31];

int hdx[8] = { -1,-2,-2,-1,1,2,2,1 };
int hdy[8] = { -2,-1,1,2,2,1,-1,-2 };

void solve(int _x, int _y) {
	queue<DATA> q;
	q.push({ _x,_y,0, k });
	check[_x][_y][k] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int ti = q.front().ti;
		int horsemoving = q.front().horsemoving;
		q.pop();
		//같은 위치를 이동하더라도 말로 이동하는게 더 빠름
		//말 처럼 움직이기
		if (x == m - 1 && y == n - 1) {
			result = ti;
			return;
		}

		if (horsemoving > 0) {
			for (int i = 0; i < 8; i++) {
				int nx = hdx[i] + x;
				int ny = hdy[i] + y;
				if (0 <= nx && nx < m && 0 <= ny && ny < n && check[nx][ny][horsemoving - 1] == false && map[nx][ny] == 0) {
					check[nx][ny][horsemoving - 1] = true;
					q.push({ nx,ny,ti + 1, horsemoving - 1 });
				}
			}
		}

		//원숭이 처럼 움직이기
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (0 <= nx && nx < m && 0 <= ny && ny < n && check[nx][ny][horsemoving] == false && map[nx][ny] == 0) {
				check[nx][ny][horsemoving] = true;
				q.push({ nx,ny,ti + 1, horsemoving });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	memset(check, false, sizeof(check));
	solve(0, 0);

	cout << result;

	return 0;
}