#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define endl "\n"

using namespace std;
int n;
int pack[1000];
int result = 0;
int dp[1001];


int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> pack[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + pack[j]);
        }
    }

    cout << dp[n] << endl;

    return 0;

}
