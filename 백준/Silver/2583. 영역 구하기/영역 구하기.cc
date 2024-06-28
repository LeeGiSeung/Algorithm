#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define endl "\n"

using namespace std;
int m, n, k;
int paper[100][100];
bool visit[100][100] = { false };

int lx, ly, rx, ry;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<int> result;

void bfs(int a, int b, int c) {
    int x, y, cost;
    cost = 0;
    deque<pair<pair<int, int>,int>>q;
    q.push_back({{ a, b },c });
    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        cost++;

        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && visit[nx][ny] == false) {
                visit[nx][ny] = true;
                q.push_back({ {nx,ny},cost + 1 });
            }
        }
    };
    result.push_back(cost);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int count = 0;
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {

        cin >> lx >> ly >> rx >> ry;

        for (int o = lx; o < rx; o++) {
            for (int y = ly; y < ry; y++) {
                visit[y][o] = true;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visit[i][j] == false) {
                visit[i][j] = true;
                count++;
                bfs(i, j, 1);

            }
        }
    }

    cout << count << endl;
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;

}