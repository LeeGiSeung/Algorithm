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

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		dp[i] = 1000;
	}

	for (int i = 1; i <= n; i++) {
		//3개 고를 수 없는 경우의 수 일 경우
		if (i - 3 < 0) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
		}
	}

	if (dp[n] % 2 == 0) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}

	return 0;
}