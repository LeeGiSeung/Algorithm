#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring> // memset을 사용하기 위한 헤더 추가

using namespace std;
int n;
int place[100][100];
int max_rain = 0;
int max_place = 0;
bool safe_zone[100][100];
bool visit[100][100];
int count_safe = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void find_safe() {
    count_safe = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (safe_zone[i][j] == true && visit[i][j] == false) {
                deque<pair<int, int>> q;
                q.push_back(make_pair(i, j));
                visit[i][j] = true;

                while (!q.empty()) {
                    int kx = q.front().first;
                    int ky = q.front().second;
                    q.pop_front();

                    for (int k = 0; k < 4; k++) {
                        int nx = kx + dx[k];
                        int ny = ky + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && safe_zone[nx][ny] == true && visit[nx][ny] == false) {
                            q.push_back(make_pair(nx, ny));
                            visit[nx][ny] = true;
                        }
                    }
                }
                count_safe++;
            }
        }
    }
    if (max_place < count_safe) max_place = count_safe;
}

void dfs() {
    for (int i = 0; i <= max_rain; i++) {
        memset(safe_zone, false, sizeof(safe_zone));
        memset(visit, false, sizeof(visit));

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (place[x][y] > i) {
                    safe_zone[x][y] = true;
                }
            }
        }
        find_safe();
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            place[i][j] = a;
            if (a > max_rain) max_rain = a;
        }
    }

    dfs();

    cout << max_place << "\n";

    return 0;
}
