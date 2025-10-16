#include <bits/stdc++.h>
using namespace std;

struct Node {
    int cur;
    int cost;
    int state; // 트랩 상태 비트마스크
    bool operator<(const Node &other) const {
        return cost > other.cost; // min-heap
    }
};

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    const int INF = 1e9;
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF));

    for (auto &r : roads) {
        int u = r[0], v = r[1], w = r[2];
        graph[u][v] = min(graph[u][v], w);
    }

    unordered_map<int,int> trap_idx;
    for (int i=0; i<traps.size(); i++) trap_idx[traps[i]] = i;

    vector<vector<int>> visited(n+1, vector<int>(1<<traps.size(), INF));

    priority_queue<Node> pq;
    pq.push({start, 0, 0});
    visited[start][0] = 0;

    while (!pq.empty()) {
        Node now = pq.top(); pq.pop();
        int cur = now.cur, cost = now.cost, state = now.state;

        if (cur == end) return cost;
        if (visited[cur][state] < cost) continue;

        bool cur_trap_on = trap_idx.count(cur) ? ((state >> trap_idx[cur]) & 1) : 0;

        for (int next=1; next<=n; next++) {
            if (graph[cur][next] == INF && graph[next][cur] == INF) continue;

            bool next_trap_on = trap_idx.count(next) ? ((state >> trap_idx[next]) & 1) : 0;

            bool reverse = cur_trap_on ^ next_trap_on;
            int next_cost;
            if (reverse) {
                if (graph[next][cur] == INF) continue;
                next_cost = cost + graph[next][cur];
            } else {
                if (graph[cur][next] == INF) continue;
                next_cost = cost + graph[cur][next];
            }

            int next_state = state;
            if (trap_idx.count(next)) next_state ^= (1 << trap_idx[next]);

            if (visited[next][next_state] > next_cost) {
                visited[next][next_state] = next_cost;
                pq.push({next, next_cost, next_state});
            }
        }
    }

    return -1; // 도달 불가 시
}

// 테스트 예시
int main() {
    int n = 4;
    int start = 1;
    int end = 4;
    vector<vector<int>> roads = {{1,2,1},{3,2,1},{2,4,1}};
    vector<int> traps = {2,3};
    cout << solution(n, start, end, roads, traps) << "\n"; // 출력: 4
}
