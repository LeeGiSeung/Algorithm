#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, W, result = 0;
int A[1001];
int dp[1001][32][3];

void solve() {
    dp[1][0][1] = A[1] == 1;
    dp[1][1][2] = A[1] == 2;

    for (int i = 2; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j][1] = dp[i - 1][j][1] + (A[i] == 1);
            if (j > 0) {
                dp[i][j][1] = max(dp[i][j][1], (dp[i][j - 1][2] + (A[i] == 1)));
            }
            dp[i][j][2] = dp[i - 1][j][2] + (A[i] == 2);
            if (j > 0) {
                dp[i][j][2] = max(dp[i][j][2], (dp[i][j - 1][1] + (A[i] == 2)));
            }
        }
    }

    for (int i = 1; i <= 2; i++) {
        for (int j = 0; j <= W; j++) {
            result = max(result, dp[T][j][i]);
        }
    }

    cout << result;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T >> W;

    for (int i = 1; i <= T; i++) {
        cin >> A[i];
    }

    solve();

    return 0;
}
