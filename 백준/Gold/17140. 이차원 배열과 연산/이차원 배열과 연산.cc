#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int map[101][101];  // 범위를 101로 수정, 충분한 공간 확보

int r, c, k;
int t = 0;
int check[101] = {0};

void find() {
    int row = 3;
    int column = 3;
    int ti = 0;

    while (true) {
        if (map[r][c] == k) {
            t = ti;
            break;
        }
        if (ti > 100) {
            t = -1;
            break;
        }

        if (row >= column) {
            int max_column = 0;
            for (int i = 1; i <= row; i++) {
                memset(check, 0, sizeof(check));
                vector<pair<int, int>> v;

                for (int j = 1; j <= column; j++) {  // 열의 범위를 잘못 설정했을 가능성이 있음
                    if (map[i][j] != 0) {
                        check[map[i][j]]++;
                    }
                }

                for (int j = 1; j <= 100; j++) {  // 100 이하의 자연수만이 유효한 값
                    if (check[j] != 0) {
                        v.push_back({check[j], j});
                    }
                }

                sort(v.begin(), v.end());  // 등장 횟수가 커지는 순, 등장 횟수가 같으면 숫자가 작은 순

                int idx = 1;
                for (int j = 0; j < v.size(); j++) {
                    if (idx > 100) break;  // 배열 범위를 넘지 않도록 제어
                    map[i][idx++] = v[j].second;
                    map[i][idx++] = v[j].first;
                }

                max_column = max(max_column, (int)v.size() * 2);

                while (idx <= 100) {  // 나머지 값은 0으로 채움
                    map[i][idx++] = 0;
                }
            }
            column = max_column;
        } else {
            int max_row = 0;
            for (int i = 1; i <= column; i++) {
                memset(check, 0, sizeof(check));
                vector<pair<int, int>> v;

                for (int j = 1; j <= row; j++) {
                    if (map[j][i] != 0) {
                        check[map[j][i]]++;
                    }
                }

                for (int j = 1; j <= 100; j++) {
                    if (check[j] != 0) {
                        v.push_back({check[j], j});
                    }
                }

                sort(v.begin(), v.end());

                int idx = 1;
                for (int j = 0; j < v.size(); j++) {
                    if (idx > 100) break;
                    map[idx++][i] = v[j].second;
                    map[idx++][i] = v[j].first;
                }

                max_row = max(max_row, (int)v.size() * 2);

                while (idx <= 100) {
                    map[idx++][i] = 0;
                }
            }
            row = max_row;
        }
        ti++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> map[i][j];
        }
    }

    if (map[r][c] == k) {
        cout << 0;
        return 0;
    }

    find();

    cout << t;

    return 0;
}
