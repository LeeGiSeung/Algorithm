#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define endl "\n"

using namespace std;

int n, l, r;
int human[2001][2001];
bool visit[2001][2001];
int human_copy[2001][2001];
int day = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> human[i][j];
        }
    }
}

void copy(int x[2001][2001], int y[2001][2001]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i][j] = y[i][j];
        }
    }
}

void bfs(int i, int j) {
    vector<pair<int, int>> union_cells;
    queue<pair<int, int>> q;
    q.push({i, j});
    visit[i][j] = true;
    int sum = 0;
    int count = 0;

    while (!q.empty()) {
        int kx = q.front().first;
        int ky = q.front().second;
        q.pop();
        union_cells.push_back({kx, ky});
        sum += human[kx][ky];
        count++;

        for (int d = 0; d < 4; d++) {
            int nx = kx + dx[d];
            int ny = ky + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny]) {
                int diff = abs(human[kx][ky] - human[nx][ny]);
                if (diff >= l && diff <= r) {
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    int new_population = sum / count;
    for (auto cell : union_cells) {
        human_copy[cell.first][cell.second] = new_population;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();

    while (true) {
        int flag = 0;
        copy(human_copy, human);
        memset(visit, false, sizeof(visit));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visit[i][j]) {
                    bfs(i, j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (human[i][j] != human_copy[i][j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        }

        if (flag == 0) {
            break;
        }

        copy(human, human_copy);
        day++;
    }

    cout << day << endl;
    return 0;
}
