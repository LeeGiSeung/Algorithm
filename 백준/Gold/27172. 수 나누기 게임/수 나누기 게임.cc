#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int v[1000002];
int card[10000002];
int score[1000002] = { 0 };


void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        card[i] = a;
        v[a] = 1;
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = card[i]; j < 1000002; j += card[i]) {
            if (v[j] == 1) {
                score[card[i]]++;
                score[j]--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << score[card[i]] << " ";
    }

}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    input();
    solve();

    return 0;


}
