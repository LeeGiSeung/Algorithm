#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int dp[101][100001];
int n, k;
int w[101];
int v[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {

        cin >> w[i] >> v[i];

    }

    for (int i = 1; i <=n; i++) {

        for (int j = 1; j <= k; j++) {

            if (j >= w[i]) {

                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);

            }

            else {

                dp[i][j] = dp[i - 1][j];

            }

        }
    }

    cout << dp[n][k];
	return 0;

}