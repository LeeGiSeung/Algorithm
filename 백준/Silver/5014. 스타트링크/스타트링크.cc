#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define endl "\n"

using namespace std;

int f, s, g, u, d;
bool visit[1000001] = { false };
int result = -1; // 초기값을 -1로 설정하여 도달하지 못했을 때를 구분

int dx[2];

void bfs() {
    deque<pair<int, int>> q;
    q.push_back({ s, 0 });
    visit[s] = true; // 시작층을 방문했다고 표시

    while (!q.empty()) {
        int floor = q.front().first;
        int count = q.front().second;
        q.pop_front();

        if (floor == g) {
            result = count;
            return;
        }

        for (int i = 0; i < 2; i++) {
            int nfloor = floor + dx[i];
            if (nfloor >= 1 && nfloor <= f && !visit[nfloor]) {
                visit[nfloor] = true;
                q.push_back(make_pair(nfloor, count + 1));
            }
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> f >> s >> g >> u >> d;

    // 시작층과 목표층이 같은 경우
    if (s == g) {
        cout << 0 << endl;
        return 0;
    }

    dx[0] = u;
    dx[1] = -d;

    bfs();

    if (result == -1) {
        cout << "use the stairs" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
