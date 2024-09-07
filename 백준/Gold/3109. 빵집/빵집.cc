#include <iostream>
using namespace std;

int n, m;
char map[10000][500]; // 가로의 최대 크기 수정

// 오른쪽, 오른쪽 위 대각선, 오른쪽 아래 대각선
int dx[3] = { -1, 0, 1 };
int dy[3] = { 1, 1, 1 };
bool check[10000][500];
int result = 0;

// DFS 함수
bool solve(int x, int y) {
    check[x][y] = true; // 방문한 좌표는 체크

    // 마지막 열에 도착하면 파이프라인을 성공적으로 설치한 것이므로 true 반환
    if (y == m - 1) {
        return true;
    }

    // 세 방향 탐색: 오른쪽 위, 오른쪽, 오른쪽 아래
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 다음 칸이 범위 안에 있고, 건물이 아니며, 아직 방문하지 않은 곳이면 탐색
        if (nx >= 0 && nx < n && !check[nx][ny] && map[nx][ny] != 'x') {
            if (solve(nx, ny)) {
                return true; // 한 경로를 찾으면 바로 종료
            }
        }
    }
    return false; // 경로를 찾지 못한 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    // 첫 번째 열에서 각 행을 시작점으로 탐색
    for (int i = 0; i < n; i++) {
        if (map[i][0] != 'x' && !check[i][0]) {
            if (solve(i, 0)) {
                result++;
            }
        }
    }

    cout << result << '\n';
    return 0;
}
