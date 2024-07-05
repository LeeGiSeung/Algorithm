#include <iostream>
#include <queue>
using namespace std;

struct point
{
    int x; int y;
};

point store[100];   // 편의점 좌표(0 <= 편의점 개수 <= 100)
point festival;     // 페스티벌 좌표
point home;         // 집 좌표
bool visited[100];

int abs(int n) {
    if (n < 0) return -n;
    return n;
}

bool BFS(int n) {
    queue<pair<int, int>> que;
    que.push({home.x, home.y}); // 시작 위치는 "집" (pair는 {}로 입력할 수 있음)

    while (!que.empty()) {
        int x = que.front().first; // pair<first, second>
        int y = que.front().second;
        que.pop();

        if (abs(festival.x - x) + abs(festival.y - y) <= 1000) return true; // 현재 위치에서 페스티벌 위치까지 1000 이하면 가능
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) {
                // 방문했던 편의점이면 pass
                continue;
            }
            if (abs(store[i].x - x) + abs(store[i].y - y) <= 1000) {        // 편의점까지 이동 가능하면
                visited[i] = 1;                                             // 해당 편의점 방문한 것으로 체크
                que.push({store[i].x, store[i].y});                         // que에 넣어줌
            }
        }
    }
    return false; // while 다 돌았는데도 도착 못했으면 false
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    int t;  // test case 개수
    cin >> t;

    while(t--) {
        int n; // 맥주를 파는 편의점의 개수
        cin >> n;

        cin >> home.x >> home.y;                // 집 좌표 받기
        for (int i=0; i < n; i++) {
            cin >> store[i].x >> store[i].y;    // 편의점 좌표 받기
        }
        cin >> festival.x >> festival.y;        // 페스티벌 좌표 받기

        bool possible = BFS(n);
        if (possible) cout << "happy\n";
        else cout << "sad\n";

        fill(visited, visited+100, false);
    }

    return 0;
}