#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, t;

int map[101][101];
bool check[101][101][2];
int result = 999999;

struct DATA
{
	int x;
	int y;
	int count;
	bool sword;
};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs() {
	queue<DATA> q;
	q.push({ 1,1,0,false });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int count = q.front().count;
		bool sword = q.front().sword;
		q.pop();

		if (map[x][y] == 2) {
			sword = true;
		}

		//cout << x << " " << y << " " << count << " " << sword << " " << endl;

		if (x == n && y == m) {
			result = min(result, count);
			//cout << "도착" << result << endl;
		}
		else {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (1 <= nx && nx <= n && 1 <= ny && ny <= m && !check[nx][ny][sword] && count + 1 <= t) {
					//벽이 있는데 검을 들고있으면 갈 수 있음
					if ((map[nx][ny] == 1 && sword == true) || map[nx][ny] == 0 || map[nx][ny] == 2) {
						check[nx][ny][sword] = true;
						q.push({ nx,ny,count + 1, sword });
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	bfs();

	if (result == 999999) {
		cout << "Fail";
	}
	else {
		cout << result;
	}

	return 0;
}