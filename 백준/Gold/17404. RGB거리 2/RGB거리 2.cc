#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int cnt = 1000001;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int house[100][100];
	
	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;

	for (int i = 1; i <= n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		house[i][0] = r;
		house[i][1] = g;
		house[i][2] = b;
	}

	for (int start = 0; start <= 2; start++) {
		int dp[1001][3];
		for (int j = 0; j <= 2; j++) {
			if (start == j) dp[1][start] = house[1][start];
			else dp[1][j] = 1000001;
		}
		for (int i = 2; i <= n; i++) {
			dp[i][0] = min(dp[i - 1][1] , dp[i - 1][2]) + house[i][0];
			dp[i][1] = min(dp[i - 1][0] , dp[i - 1][2]) + house[i][1];
			dp[i][2] = min(dp[i - 1][0] , dp[i - 1][1]) + house[i][2];
		}
		for (int j = 0; j <= 2; j++) {
			if (start == j) continue;
			cnt = min(dp[n][j], cnt);
		}
	}

	cout << cnt;

	return 0;
}
