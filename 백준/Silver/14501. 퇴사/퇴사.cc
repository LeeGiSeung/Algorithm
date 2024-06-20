#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int result = 1;
int n;

int ti[16];
int pi[16];
int res[16] = { 0 };

void bfs() {
    int k = 0;
    for (int i = 0; i <= n; i++) {
        res[i] = max(k, res[i]);
        if (i + ti[i] <= n) {
            res[ti[i] + i] = max(res[ti[i] + i], res[i] + pi[i]);
        }
        k = max(k, res[i]);
    }
    cout << k << endl;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ti[i] = a;
        pi[i] = b;
    }

    bfs();

    return 0;

}
