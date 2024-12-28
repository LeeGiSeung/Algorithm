#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

long long dp[101][11];
long long result = 0;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	dp[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			}
			else if (j == 9) 
				{ dp[i][j] = dp[i - 1][j - 1] % 1000000000; }
			else 
			{ dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000; }
		}
	}

	for (int i = 0; i <= 9; i++) {
		result += dp[n][i];
	}

	cout << result % 1000000000;

	return 0;
}