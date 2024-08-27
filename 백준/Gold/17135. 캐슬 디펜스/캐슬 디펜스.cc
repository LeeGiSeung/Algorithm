#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// 좌표 구조체
struct Point {
    int x;
    int y;
};

vector<Point> enemy; // 적군 좌표
int map[17][17] = { 0, };
int N, M, D;

// 정렬 기준
bool compare(Point a, Point b) {
    return a.y < b.y;
}

// 적 위치 업데이트
bool updateEnemy() {
    bool remain = false;
    vector<Point> newEnemy;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] == 1) {
                remain = true; // 한마리라도 있으면 true
                newEnemy.push_back({ i,j });
            }
        }
    }
    enemy = newEnemy; // 새로운 위치 vector 적용
    return remain;
}

// 궁수 공격 함수
int attack(int arr[]) {
    int kill = 0; // 죽은 적군 수

    // i = 각 궁수
    for (int i = 0; i < 3; i++) {
        int min_dist = 9999;
        vector<Point> tmp; // 제거 대상 후보
        for (int j = 0; j < enemy.size(); j++) {
            int dist = abs(N + 1 - enemy[j].x) + abs(arr[i] - enemy[j].y); // 거리 계산

            // 해당 적군의 거리가 지금까지의 최소 거리보다 작을 때
            if (dist < min_dist) {
                min_dist = dist;
                tmp.clear(); // 지금까지의 제거 대상 후보 초기화
                tmp.push_back({ enemy[j].x,enemy[j].y }); // 후보 리스트에 추가
            }
            // 최소 거리와 같을 때
            else if (dist == min_dist) {
                tmp.push_back({ enemy[j].x,enemy[j].y }); // 후보 리스트에 추가
            }
        }
        sort(tmp.begin(), tmp.end(), compare); // 정렬 기준에 따라 정렬
        int dist = abs(N + 1 - tmp[0].x) + abs(arr[i] - tmp[0].y); // 최우선에 있는 적

        // 사정거리 D안에 있고, 그 적이 아직 제거안됐을 때
        if (dist <= D && map[tmp[0].x][tmp[0].y] == 1)
        {
            map[tmp[0].x][tmp[0].y] = 0; // 적군 제거
            kill++; // 제거수 + 1
        }
    }
    return kill;
}

// 적군 움직이는 함수
void move() {
    // 죽은거 제외하고 나머지 적군들 업데이트
    updateEnemy();
    int cmap[17][17] = { 0, }; // 맵 복사
    for (int i = 0; i < enemy.size(); i++) {
        if (enemy[i].x + 1 == N + 1) continue; // 성에 도달한건 새로운 맵에 안담음
        cmap[enemy[i].x + 1][enemy[i].y] = 1; // x+1로 전진
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) map[i][j] = cmap[i][j]; // 새로운 맵을 원래 맵으로
}

// 궁수가 해당 배치일 때 시뮬레이션 돌리는 함수
int setting(int arr[]) {

    int ans = 0;
    // 적이 없을때까지 반복
    while (updateEnemy()) {
        ans += attack(arr);
        move();
    }
    return ans;
}

// 원래 맵으로 초기화
void reset(int origin[17][17]) {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) map[i][j] = origin[i][j];
}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M >> D;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) enemy.push_back({ i,j });
        }

    int origin[17][17];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) origin[i][j] = map[i][j];
    int ans = 0;
    // 삼중 반복문으로 모든 궁수 배치 경우의 수
    for (int i = 1; i <= M - 2; i++) {
        for (int j = i + 1; j <= M - 1; j++) {
            for (int k = j + 1; k <= M; k++) {
                reset(origin); // 할때마다 초기화
                int arr[3] = { i,j,k };
                int val = setting(arr);
                ans = max(ans, val); // 최대값
            }
        }
    }
    cout << ans;
}