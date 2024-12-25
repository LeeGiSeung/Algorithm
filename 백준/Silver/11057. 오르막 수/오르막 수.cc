#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, a;
long long dp[1001][10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	dp[2][0] = 1;

	cin >> n;
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	//n
	for (int j = 2; j <= n; j++) {
		//1~9까지
		for (int i = 1; i < 10; i++) {
			dp[j][i] = (dp[j - 1][i] + dp[j][i - 1]) % 10007;
		}
	}
	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += dp[n][i];
	}

	cout << result % 10007;

	return 0;
}