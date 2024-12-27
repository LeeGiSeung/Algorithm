#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int dp[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i <= n; i++) {
		//3개 고를 수 없는 경우의 수 일 경우
		if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4]) dp[i] = 1;
		else dp[i] = 0;
	}

	if (dp[n]) {
		cout << "SK";
	}
	else {
		cout << "CY";
	}

	return 0;
}