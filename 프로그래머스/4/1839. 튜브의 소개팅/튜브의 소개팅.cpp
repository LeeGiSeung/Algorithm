#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct Node {
    int y, x;          // 좌표
    long long dist;    // 이동 거리
    long long time;    // 누적 시간
};

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

// BFS 기반 시간 제한 이동 최소 거리 탐색
vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    const long long INF_DIST = 2500;
    const long long INF_TIME = 1e10;
    vector<vector<pair<long long, long long>>> visited(m, vector<pair<long long, long long>>(n, {INF_DIST, INF_TIME}));

    // 시작점 초기화
    visited[0][0] = {-1, INF_TIME};
    queue<Node> q;
    q.push({0, 0, 0, 0});

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        // 도착점이라면 더 이상 진행할 필요 없음
        if (cur.y == m - 1 && cur.x == n - 1) {
            if (visited[cur.y][cur.x].first >= cur.dist && cur.time <= visited[cur.y][cur.x].second) {
                visited[cur.y][cur.x] = {cur.dist, cur.time};
            }
            continue;
        }

        // 이미 더 좋은 경로가 있다면 가지치기
        if (visited[cur.y][cur.x].first < cur.dist && visited[cur.y][cur.x].second < cur.time)
            continue;

        // 4방향 탐색
        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n)
                continue;
            if (time_map[ny][nx] == -1)
                continue;

            long long next_time = cur.time + time_map[ny][nx];
            if (next_time > s)
                continue;

            // 이전보다 더 빠른 시간으로 도달 가능하다면
            if (visited[ny][nx].second > next_time) {
                if (!(ny == m - 1 && nx == n - 1)) { // 마지막 노드는 위에서 처리
                    visited[ny][nx] = {cur.dist + 1, next_time};
                }
                q.push({ny, nx, cur.dist + 1, next_time});
            }
        }
    }

    vector<int> answer(2);
    answer[0] = visited[m - 1][n - 1].first;
    answer[1] = visited[m - 1][n - 1].second;
    return answer;
}
