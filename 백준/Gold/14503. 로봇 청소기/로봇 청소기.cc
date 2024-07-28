#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int robot[51][51];
bool clean[51][51];
int cnt;
int n, m;
int a, b, d;

// 북, 동, 남, 서 방향을 나타내는 배열
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve(int x, int y, int d) {
    // 현재 칸 청소
    if (!clean[x][y]) {
        clean[x][y] = true;
        cnt++;
    }

    // 4 방향 탐색
    for (int i = 0; i < 4; i++) {
        // 반시계 방향으로 회전
        d = (d + 3) % 4;
        int nx = x + dx[d];
        int ny = y + dy[d];

        // 청소하지 않은 빈 칸이 있는 경우
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && robot[nx][ny] == 0 && !clean[nx][ny]) {
            solve(nx, ny, d);
            return;
        }
    }

    // 4 방향 모두 청소가 되어있거나 벽인 경우
    int back = (d + 2) % 4;
    int bx = x + dx[back];
    int by = y + dy[back];

    // 뒤로 갈 수 있는 경우
    if (bx >= 0 && by >= 0 && bx < n && by < m && robot[bx][by] == 0) {
        solve(bx, by, d);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> a >> b >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> robot[i][j];
        }
    }

    solve(a, b, d);

    cout << cnt << endl;

    return 0;
}
