#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int dp[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		dp[i] = 100;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i - j*j < 0) break;
			dp[i] = min(dp[i - j*j] + 1, dp[i]);
		}
	}
	
	cout << dp[n];

	return 0;
}