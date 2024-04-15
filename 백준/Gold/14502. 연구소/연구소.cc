#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int n, m;
int map[50][50];
int semap[50][50];
int result = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void input() {

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

}

void copyMap(int a[50][50], int b[50][50]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void spreadImpact() {
    queue<pair<int, int>> q;
    int spreadMap[50][50];
    copyMap(spreadMap, semap);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spreadMap[i][j] == 2)
                q.push(make_pair(i, j));
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (0 <= nx && nx < n && 0 <= ny && ny < m && spreadMap[nx][ny] == 0) {
                spreadMap[nx][ny] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }
    int seresult = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (spreadMap[i][j] == 0) {
                seresult++;
            }
        }
    }
    result = max(result, seresult);
}

void wall(int cnt) {
    if (cnt == 3) {
        spreadImpact();
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (semap[i][j] == 0) {
                semap[i][j] = 1;
                wall(cnt + 1);
                semap[i][j] = 0;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                copyMap(semap, map);
                semap[i][j] = 1;
                wall(1);
                semap[i][j] = 0;
            }
        }
    }

    cout << result;

    return 0;

}
