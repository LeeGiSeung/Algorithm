#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct CCTV
{
	int x;
	int y;
};

int n, m;

int cctv[8] = { 0 };
int ct = 0;
//cctv 목록
vector<CCTV> v;

int map[9][9];
int result = 999999999;

//1번은 네번 반복
//우 상 좌 하
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

void check(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		x = nx;
		y = ny;
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) return;
		if (map[nx][ny] == 6) return;
		if (map[nx][ny] != 0) continue;
		map[nx][ny] = -1;
	}
}

void backtracking(int cnt) {

	if (cnt == v.size()) {
		int cmp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) {
					cmp++;
				}
			}
		}
		result = min(cmp, result);
		return;
	}

	int x = v[cnt].x;
	int y = v[cnt].y;
	int tmp[9][9];

	for (int dir = 0; dir < 4; dir++) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				tmp[i][j] = map[i][j];

		if (tmp[x][y] == 1) {
			check(x, y, dir);
		}
		else if (tmp[x][y] == 2) {
			check(x, y, dir);
			check(x, y, dir + 2);
		}
		else if (tmp[x][y] == 3) {
			check(x, y, dir);
			check(x, y, dir + 1);
		}
		else if (tmp[x][y] == 4) {
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
		}
		else if (tmp[x][y] == 5) {
			check(x, y, dir);
			check(x, y, dir + 1);
			check(x, y, dir + 2);
			check(x, y, dir + 3);
		}
		backtracking(cnt + 1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				map[i][j] = tmp[i][j];
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	//입력 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			map[i][j] = a;
			if (a != 6 && a != 0) {
				v.push_back({ i,j});
			}
		}
	}

	backtracking(0);
	
	cout << result;

	return 0;
}