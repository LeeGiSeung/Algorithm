#include <iostream>
#include <algorithm>
using namespace std;



char map[10000][10000]; // 별을 찍는 맵

// k = 0 일 때 그림을 그리는 것(최소 단위)
void unit(int sx, int sy) {
    map[sx][sy] = '*';
    map[sx + 1][sy - 1] = '*';
    map[sx + 1][sy + 1] = '*';
    for (int i = sy - 2; i <= sy + 2; i++) map[sx + 2][i] = '*';
}

// 중심좌표를 기준으로 그림을 그림-> (sx,sy)좌표에 길이 len으로 그림
void Draw(int sx, int sy, int len) {
    // N = 3이면 최소단위 unit() 호출
    if (len == 3) {
        unit(sx, sy);
        return;
    }
    // len < 3 이면 그냥 return
    else if (len < 3) return;

    int halfX = len / 2; // 절반으로 분할
    int halfY = len / 2; // 절반으로 분할
    Draw(sx, sy, len / 2); // 맨 위에 있는 삼각형
    Draw(sx + halfX, sy - halfY, len / 2); // 왼쪽 삼각형
    Draw(sx + halfX, sy + halfY, len / 2); // 오른쪽 삼각형

}
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int sy = (2 * N - 1) / 2;
    fill(&map[0][0], &map[9999][10000], ' ');
    Draw(0, sy, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) cout << map[i][j];
        cout << "\n";
    }
}