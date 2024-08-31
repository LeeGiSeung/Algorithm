#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;

int map[500][500];
int dp[500][500];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

bool check[500][500] = { false };

int solve(int x, int y) {

	if (x == n - 1 && y == m - 1) {
		return 1;
	}

	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//범위가 넘은건 확인할 필요가 없음
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		//다음 층 값이 현재 층 보다 크거나 같으면 경사가 아니여서 갈 수 없음
		if (map[nx][ny] >= map[x][y]) continue;
		//위 조건이 모두 충족하는데 만약 다음칸이 이미 방문했다면 이건 새로운 경로 라는 것 +1을 해주고 return해서 불필요한 연산 하지 않음

		//범위가 넘지 않았고, 현재보다 낮은 높이고, 이미 방문하지도 않았더라면 새로운 루트 check를 true로 해주고 dfs 추가 실행
		dp[x][y] += solve(nx, ny);
	}
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	input();
	cout<<solve(0,0);

	return 0;
}