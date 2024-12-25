#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, a;
long long dp[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (n--) {
		cin >> a;
		for (int i = 4; i <= a; i++) {
			int k = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
			dp[i] = k;
		}
		cout << dp[a] % 1000000009 << "\n";
	}

	return 0;
}