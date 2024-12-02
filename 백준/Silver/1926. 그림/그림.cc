#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N, M;
int MAP[501][501];
int result;
int ct;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[501][501];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	int k = 1;
	check[x][y] = true;
	q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && check[nx][ny] == false && MAP[nx][ny] == 1) {
				k++;
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	result = max(result, k);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!check[i][j] && MAP[i][j] == 1) {
				bfs(i, j);
				ct++;
			}
		}
	}

	cout << ct << "\n";
	cout << result;

	return 0;
}