#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> v[401]; // 학생 수는 최대 20*20 = 400, 따라서 401로 변경
int cl[20][20]; // 교실의 크기 최대 20x20
vector<int> order;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void input() {
    cin >> n;

    int nn = n * n;

    // 각 학생들이 선호하는 학생 입력 받음
    for (int i = 0; i < nn; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        order.push_back(a);
        v[a].push_back(b);
        v[a].push_back(c);
        v[a].push_back(d);
        v[a].push_back(e);
    }

    memset(cl, 0, sizeof(cl)); // 올바르게 초기화
}

void solve() {
    for (int i = 0; i < order.size(); i++) {
        int student = order[i];
        int hit_x = -1, hit_y = -1;
        int best_friends = -1, best_empty = -1;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (cl[x][y] != 0) continue; // 이미 채워진 칸은 패스

                int friends = 0, empty = 0;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                        if (cl[nx][ny] == 0) empty++;
                        for (int k = 0; k < 4; k++) {
                            if (cl[nx][ny] == v[student][k]) friends++;
                        }
                    }
                }

                // 조건 1: 좋아하는 학생이 인접한 칸에 가장 많은 칸
                if (friends > best_friends) {
                    best_friends = friends;
                    best_empty = empty;
                    hit_x = x;
                    hit_y = y;
                }
                // 조건 2: 1을 만족하는 칸이 여러 개면 빈칸이 가장 많은 칸
                else if (friends == best_friends) {
                    if (empty > best_empty) {
                        best_empty = empty;
                        hit_x = x;
                        hit_y = y;
                    }
                    // 조건 3: 2를 만족하는 칸도 여러 개인 경우 행 번호가 가장 작은 칸, 열 번호가 가장 작은 칸
                    else if (empty == best_empty) {
                        if (hit_x > x || (hit_x == x && hit_y > y)) {
                            hit_x = x;
                            hit_y = y;
                        }
                    }
                }
            }
        }

        cl[hit_x][hit_y] = student;
    }
}

void count_student() {
    int satisfaction = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int student = cl[x][y];
            int friends = 0;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    for (int k = 0; k < 4; k++) {
                        if (cl[nx][ny] == v[student][k]) friends++;
                    }
                }
            }

            if (friends == 1) satisfaction += 1;
            else if (friends == 2) satisfaction += 10;
            else if (friends == 3) satisfaction += 100;
            else if (friends == 4) satisfaction += 1000;
        }
    }

    cout << satisfaction << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
    count_student();

    return 0;
}
