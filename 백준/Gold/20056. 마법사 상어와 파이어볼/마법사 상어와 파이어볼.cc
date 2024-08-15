#include <iostream>
#include <vector>

#define MAX 55
#define endl "\n"
using namespace std;

struct FIREBALL {
    int x;
    int y;
    int kg;
    int speed;
    int direct;
};

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int T_Dir[] = { 0, 2, 4, 6 };
int F_Dir[] = { 1, 3, 5, 7 };

int n, m, k;
vector<FIREBALL> MAP[MAX][MAX];
vector<FIREBALL> FireBall;

void MoveFireBall() {
    // Initialize map
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            MAP[i][j].clear();
        }
    }

    // Move fireballs
    for (auto &fb : FireBall) {
        int x = fb.x;
        int y = fb.y;
        int move = fb.speed % n;
        int nx = (x + dx[fb.direct] * move - 1 + n) % n + 1;
        int ny = (y + dy[fb.direct] * move - 1 + n) % n + 1;

        MAP[nx][ny].push_back({ nx, ny, fb.kg, fb.speed, fb.direct });
    }
}

void SumFireBall() {
    vector<FIREBALL> temp;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (MAP[i][j].size() == 0) continue;
            if (MAP[i][j].size() == 1) {
                temp.push_back(MAP[i][j][0]);
                continue;
            }

            int kg_sum = 0;
            int speed_sum = 0;
            int cnt = MAP[i][j].size();
            bool odd = true;
            bool even = true;

            for (const auto &fb : MAP[i][j]) {
                kg_sum += fb.kg;
                speed_sum += fb.speed;
                if (fb.direct % 2 == 0) odd = false;
                else even = false;
            }

            int kg_sum_5 = kg_sum / 5;
            int speed_sum_f = speed_sum / cnt;

            if (kg_sum_5 == 0) continue;

            if (odd || even) {
                for (int b = 0; b < 4; b++) temp.push_back({ i, j, kg_sum_5, speed_sum_f, T_Dir[b] });
            } else {
                for (int b = 0; b < 4; b++) temp.push_back({ i, j, kg_sum_5, speed_sum_f, F_Dir[b] });
            }
        }
    }
    FireBall = temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int ri, ci, mi, si, di;
        cin >> ri >> ci >> mi >> si >> di;
        FireBall.push_back({ ri, ci, mi, si, di });
        MAP[ri][ci].push_back({ ri, ci, mi, si, di });
    }

    for (int a = 0; a < k; a++) {
        MoveFireBall();
        SumFireBall();
    }

    int answer = 0;
    for (const auto &fb : FireBall) {
        answer += fb.kg;
    }

    cout << answer << endl;

    return 0;
}
