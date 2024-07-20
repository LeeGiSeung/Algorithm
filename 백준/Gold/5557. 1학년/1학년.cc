#include <iostream>
using namespace std;

int num[101];
long long dp[101][21];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];

	dp[1][num[1]] = 1;

	for (int i = 2; i <= n - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (j + num[i] <= 20) dp[i][j + num[i]] += dp[i - 1][j];
				if(j - num[i] >= 0) dp[i][j - num[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[n - 1][num[n]] << endl;

	return 0;
}