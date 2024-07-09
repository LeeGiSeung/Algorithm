#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;
int n, m;
int map[51][51];

bool visit[51][51] = { false };
bool treasure[51][51];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int start_pointX = 0;
int start_pointY = 0;

int end_pointX = 0;
int end_pointY = 0;

int result = 0;
int final_result = 99999999;

//매 지점이 L이 확인하고 해당 지점이 l이면 그 값을 저장한뒤 여기서 최장 거리 보물 지점을 탐색함 그 값을 저장하고 start point와 end point를 벡터로 저장

//함수 하나 더 만들어서 start point, end point 매개변수로 넣어서 최단거리 찾으면됨 visit은 초기화하고 맵은 변화없으니 그대로 사용 맵 복사 안해도도리듯



void max_bfs(int x, int y) {
    int imx = x;
    int imy = y;
    int cost = 0;
    queue<pair<pair<int, int>,int>> q;
    q.push({ { x,y } ,cost});
    visit[x][y] = true;

    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        cost = q.front().second;


        if (cost > result) {
            result = cost;
            start_pointX = imx;
            start_pointY = imy;

            end_pointX = x;
            end_pointY = y;
        }

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && visit[nx][ny] == false && map[nx][ny] == 'L') {
                visit[nx][ny] = true;
                q.push({ {nx,ny} ,cost+1 });
            }

        }

    }
}

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            map[i][j] = a;
        }
    }
}

void final_bfs(int sx,int sy,int ex,int ey) {

    int x = sx;
    int y = sy;
    int cost = 0;

    queue<pair<pair<int, int>, int>> q;

    q.push({ {sx,sy},0 });
    visit[sx][sy] = true;
    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        cost = q.front().second;
        q.pop();
        if (ex == x && ey == y && cost<final_result) {
            final_result = cost;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && visit[nx][ny] == false && map[nx][ny] == 'L') {
                visit[nx][ny] = true;
                q.push({ {nx,ny} ,cost+1 });

            }

        }

    }
    cout << final_result;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    input();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L') {
                max_bfs(i,j);
                memset(visit, false, sizeof(visit));
            }
        }
    }

    final_bfs(start_pointX, start_pointY, end_pointX, end_pointY);

    return 0;
}
