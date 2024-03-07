#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <cstring>

using namespace std;
int ary[2][100001] = { 0 };
int dp[2][100001] = { 0 };
int T;
int n;


void input() {
		cin >> n;
		for (int z = 0; z < 2; z++)
		{
			for (int j = 1; j <= n; j++) {
				cin >> ary[z][j];
			}
		}
}

void dp_cal() {

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = ary[0][1];
		dp[1][1] = ary[1][1];

		for (int j = 2; j <= n; j++) {
			dp[0][j] = max(dp[1][j - 1], dp[1][j - 2])+ary[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[0][j - 2])+ary[1][j];
		}
		cout << max(dp[0][n], dp[1][n]) << "\n";
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int k = 0; k < T; k++) {

		input();
		dp_cal();
	}

	return 0;
}