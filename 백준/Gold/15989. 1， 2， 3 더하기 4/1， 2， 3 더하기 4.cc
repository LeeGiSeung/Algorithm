#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> v;
int t;

int idx = 0;

int dp[10001][4];

void solve() {
	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[1][3] = 0;

	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[2][3] = 0;

	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int i = 4; i <= 10000; i++) {
		dp[i][1] = 1;
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i-3][3];
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	solve();
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		cout << dp[a][1] + dp[a][2] + dp[a][3] << "\n";
	}

	return 0;
}