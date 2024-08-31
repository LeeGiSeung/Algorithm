#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int map[500][500];
int dp[500][500];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
}

int dfs(int x, int y) {
    // 도착점에 도달한 경우
    if (x == n - 1 && y == m - 1) {
        return 1;
    }

    // 이미 방문해서 경로 수가 계산된 경우
    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    dp[x][y] = 0; // 초기화

    // 4방향 탐색
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 범위 체크
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            // 내리막길인 경우만 이동
            if (map[nx][ny] < map[x][y]) {
                dp[x][y] += dfs(nx, ny);
            }
        }
    }

    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    memset(dp, -1, sizeof(dp)); // DP 테이블을 -1로 초기화

    cout << dfs(0, 0) << "\n";

    return 0;
}
