#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define endl "\n"

int n, m;
char map[51][51];
bool visit[51][51];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y, int &max_dist, int &end_x, int &end_y) {
    queue<pair<pair<int, int>, int>> q;
    q.push({ {x, y}, 0 });
    visit[x][y] = true;

    while (!q.empty()) {
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (dist > max_dist) {
            max_dist = dist;
            end_x = cur_x;
            end_y = cur_y;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] == 'L') {
                visit[nx][ny] = true;
                q.push({ {nx, ny}, dist + 1 });
            }
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int max_distance = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L') {
                memset(visit, false, sizeof(visit));
                int local_max_dist = 0, end_x, end_y;
                bfs(i, j, local_max_dist, end_x, end_y);
                max_distance = max(max_distance, local_max_dist);
            }
        }
    }

    cout << max_distance << endl;
    return 0;
}
