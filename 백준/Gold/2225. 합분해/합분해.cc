#include <iostream>
using namespace std;

int result = 0;

int dp[201][201];

int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		dp[i][1] = 1;
	}

	for (int i = 1; i <= k; i++) {
		dp[1][i] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= 1000000000;
		}
	}
	
	cout << dp[n][k];

	return 0;
}