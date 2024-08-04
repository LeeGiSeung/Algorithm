#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>


using namespace std;
int n, k, s, x, y;
int map[201][201] = {0};

bool visit[200][200] = { false };

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<pair<int, int>> number[1001];

void solve(int cur, int _x, int _y) {
	visit[_x][_y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = _x + dx[i];
		int ny = _y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n && map[nx][ny] == 0) {
			map[nx][ny] = cur;
			number[cur].push_back({ nx,ny });
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			map[i][j] = a;
			number[a].push_back({ i,j });
		}
	}

	cin >> s >> x >> y;


	for (int i = 0; i < s; i++) {
		for (int j = 1; j <= k; j++) {
			//숫자 1부터 위치값 넘김
			int k = number[j].size();
			for (int z = 0; z < k; z++) {
				if (visit[number[j][z].first][number[j][z].second] == false) {
					solve(j, number[j][z].first, number[j][z].second);
				}
			}
		}
	}

	cout << map[x-1][y-1];

	return 0;
}
