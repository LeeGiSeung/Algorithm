#include <string>
#include <cmath>
using namespace std;

int dy[4] = {0, -1, 1, 0};       // d, l, r, u
int dx[4] = {1, 0, 0, -1};
char dir[4] = {'d', 'l', 'r', 'u'};
string answer = "impossible";
bool found = false;

void dfs(int x, int y, int r, int c, int k, string path, int depth, int n, int m) {
    if (found) return;
    
    int remain = abs(x - r) + abs(y - c);
    if (depth + remain > k || (k - depth - remain) % 2 != 0) return;

    if (depth == k) {
        if (x == r && y == c) {
            answer = path;
            found = true;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        dfs(nx, ny, r, c, k, path + dir[i], depth + 1, n, m);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int dist = abs(x - r) + abs(y - c);
    if (dist > k || (k - dist) % 2 != 0) return "impossible";

    answer = "impossible";
    found = false;
    dfs(x, y, r, c, k, "", 0, n, m);
    return answer;
}
