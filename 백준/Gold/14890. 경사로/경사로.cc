#include <iostream>
#include <vector>

using namespace std;

int n, l;
int map[100][100];

int result = 0;

// 경사로 설치를 확인하는 함수
bool canBuildSlope(vector<int>& line) {
    vector<bool> used(n, false); // 경사로가 사용된 위치를 추적하기 위한 배열

    for (int i = 1; i < n; i++) {
        if (line[i] == line[i - 1]) {
            continue; // 높이가 같으면 다음으로 진행
        } 
        else if (line[i] == line[i - 1] + 1) { // 높이가 1 증가하는 경우
            // 경사로를 놓을 수 있는지 확인
            for (int j = 1; j <= l; j++) {
                if (i - j < 0 || line[i - j] != line[i - 1] || used[i - j]) {
                    return false;
                }
            }
            for (int j = 1; j <= l; j++) {
                used[i - j] = true; // 경사로 설치
            }
        } 
        else if (line[i] == line[i - 1] - 1) { // 높이가 1 감소하는 경우
            // 경사로를 놓을 수 있는지 확인
            for (int j = 0; j < l; j++) {
                if (i + j >= n || line[i + j] != line[i] || used[i + j]) {
                    return false;
                }
            }
            for (int j = 0; j < l; j++) {
                used[i + j] = true; // 경사로 설치
            }
            i += l - 1; // 경사로가 설치된 위치는 건너뜀
        } 
        else { // 높이 차이가 1 이상인 경우
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    // 가로 방향 검사
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            row.push_back(map[i][j]);
        }
        if (canBuildSlope(row)) {
            result++;
        }
    }

    // 세로 방향 검사
    for (int i = 0; i < n; i++) {
        vector<int> col;
        for (int j = 0; j < n; j++) {
            col.push_back(map[j][i]);
        }
        if (canBuildSlope(col)) {
            result++;
        }
    }

    cout << result;

    return 0;
}
