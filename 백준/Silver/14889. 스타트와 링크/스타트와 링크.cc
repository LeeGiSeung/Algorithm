#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int soccer [22][22];
deque<int> start;
deque<int> link;
int start_result = 0, link_result = 0, result = 100000000;
bool visit[25];

void dfs(int x, int y) {
    if (x == n / 2) {
        int start_result = 0, link_result = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (visit[i] == true && visit[j] == true) start_result += soccer[i][j];
                else if (visit[i] == false && visit[j] == false) link_result += soccer[i][j];
            }
        }
        int temp = abs(start_result - link_result);
        if (result > temp) result = temp;
    }
    else {
        for (int k = y; k < n; k++) {
            visit[k] = true;
            dfs(x + 1, k + 1);
            visit[k] = false;
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
			cin >> soccer[i][j];
        }
    }

    dfs(0, 1);

    cout << result << "\n";

    return 0;

}