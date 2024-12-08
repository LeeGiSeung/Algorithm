#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n;
int cur[1001];
int dp[1001];
int result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> cur[i];
	}

	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		dp[i] = cur[i];
		for (int j = 1; j <= i; j++) {
			//현재 값이 dp값 보다 클 경우
			if (cur[i] > cur[j]) {
				dp[i] = max(cur[i] + dp[j], dp[i]);
			}
		}
	}

	result = dp[1];

	for (int i = 2; i <= n; i++) {
		if (result < dp[i]) result = dp[i];
	}

	cout << result;

	return 0;
}