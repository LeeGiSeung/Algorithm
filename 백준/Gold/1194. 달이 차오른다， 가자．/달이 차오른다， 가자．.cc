#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
char moon[50][50];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool check[50][50][64];  // 좌표별로 열쇠 상태(비트마스크)를 저장
int result = -1;

struct MINSIK {
    int x, y, keys, count;
};

void solve(int mx, int my) {
    queue<MINSIK> q;
    q.push({ mx, my, 0, 0 });  // (x, y, 획득한 열쇠 상태, 이동 횟수)
    check[mx][my][0] = true;  // 시작 위치에서 열쇠가 없는 상태로 체크

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int keys = q.front().keys;
        int count = q.front().count;
        q.pop();

        // 출구에 도달하면 탈출
        if (moon[x][y] == '1') {
            result = count;
            return;
        }

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && moon[nx][ny] != '#') {
                int new_keys = keys;
                if ('a' <= moon[nx][ny] && moon[nx][ny] <= 'f') {
                    new_keys |= (1 << (moon[nx][ny] - 'a'));
                }

                if ('A' <= moon[nx][ny] && moon[nx][ny] <= 'F') {
                    if (!(keys & (1 << (moon[nx][ny] - 'A')))) {
                        continue;
                    }
                }

                if (check[nx][ny][new_keys]) continue;
                check[nx][ny][new_keys] = true;
                q.push({ nx,ny,new_keys,count + 1 });


            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int mx, my;  // 민식이의 초기 위치

    // 미로 입력
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            moon[i][j] = s[j];
            if (moon[i][j] == '0') {
                mx = i;
                my = j;
            }
        }
    }

    // BFS로 문제 해결
    solve(mx, my);

    // 결과 출력
    cout << result << "\n";
    return 0;
}
