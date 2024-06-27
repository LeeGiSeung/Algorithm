#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define endl "\n"

using namespace std;
int t;
int a, b, c, d, e;
int chess[300][300];

int dx[8] = { 2, 1, -1,-2, -2, -1,  1, 2 };
int dy[8] = { 1, 2, 2 , 1, -1, -2, -2, -1 };
bool visit[300][300];

void bfs(int size, int sx, int sy, int gx, int gy) {

    deque<pair<int,pair<int, int>>> q;
    q.push_back({ 0,{sx,sy} });
    visit[sx][sy] = true;
    while (!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cost = q.front().first;
        q.pop_front();
        if (x == gx && y == gy) {
            cout << cost << endl;
            return;
        }
        
        for (int i = 0; i < 8; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && nx < size && ny >= 0 && ny < size && visit[nx][ny] == false) {
                visit[nx][ny] = true;
                q.push_back({ cost + 1,{nx,ny} });
            }
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> t;

    for (int i = 0; i < t; i++) {
        memset(chess, 0, sizeof(chess));
        memset(visit, false, sizeof(visit));
        cin >> a;
        cin >> b;
        cin >> c;
        cin >> d;
        cin >> e;
        bfs(a,b,c,d,e);
    }

    return 0;

}