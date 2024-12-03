#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, m, t;
char map[1010][1010];
int firemap[1010][1010];
bool check[1010][1010];
int result;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char a;
int sx, sy;
int ti;

struct fire_data {
	int x;
	int y;
	int firetime;
};

struct sg_data {
	int x;
	int y;
	int sgtime;
};

int bfs(int x, int y) {
	queue<sg_data> q;
	q.push({ x,y,0 });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int sgtime = q.front().sgtime;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
				return sgtime + 1;
			}

			if (0 <= nx && nx < m && 0 <= ny && ny < n && sgtime + 1 < firemap[nx][ny] && map[nx][ny] != '#' && !check[nx][ny]) {
				check[nx][ny] = true;
				q.push({ nx,ny, sgtime + 1 });
			}
		}
	}
	return -1;
}

void fire(vector<pair<int,int>> v) {
	queue<fire_data> q;
	for (int i = 0; i < v.size(); i++) {
		q.push({ v[i].first, v[i].second });
		firemap[v[i].first][v[i].second] = 0;
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int firetime = q.front().firetime;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < m && 0 <= ny && ny < n && firetime + 1 < firemap[nx][ny] && map[nx][ny] != '#') {
				firemap[nx][ny] = firetime + 1;
				q.push({ nx,ny,firetime + 1 });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(map, ' ', sizeof(map));
		memset(check, false, sizeof(check));
		memset(firemap, 9999, sizeof(firemap));
		vector<pair<int, int>> firev;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a;
				if (a == '@') {
					sx = i;
					sy = j;
				}
				else if (a == '*') {
					firev.push_back({ i,j });
				}
				map[i][j] = a;
			}
		}

		fire(firev);

		int re = bfs(sx, sy);

		if (re == -1) {
			cout << "IMPOSSIBLE" << "\n";
		}
		else {
			cout << re << "\n";
		}
	}



	return 0;
}