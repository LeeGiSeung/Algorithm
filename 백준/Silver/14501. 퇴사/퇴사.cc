#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int ti[16];
int pi[16];
int res[16] = { 0 };
int n;
int k = 0;

void bfs() {
    for (int i = 0; i <= n; i++) {
        res[i] = max(res[i], k);
        if (i + ti[i] <= n) {
            res[i + ti[i]] = max(res[i + ti[i]], res[i] + pi[i]);
        }
        k = max(k, res[i]);
    }
    cout << k << endl;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ti[i] >> pi[i];
    }

    bfs();
   

    return 0;

}