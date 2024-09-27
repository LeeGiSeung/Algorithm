#include <iostream>
using namespace std;

string s;

int dp[5001];
int arr[5001];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	//25114
	//2 25 5 1 11 1 14 4
	for (int i = 1; i <= s.size(); i++) {
		arr[i] = s[i - 1] - '0';
	}

	dp[0] = 1;

	for (int i = 1; i <= s.size(); i++) {
		//1의 자리가 1~9 사이이 경우 답 증가 0일 경우는 답이 아님
		if (1 <= arr[i] && arr[i] <= 9) {
			dp[i] = (dp[i - 1] + dp[i]) % 1000000;
		}

		if (i == 1) continue;

		int k = arr[i - 1] * 10 + arr[i];

		if (10 <= k && k <= 26) {
			dp[i] = (dp[i - 2] + dp[i]) % 1000000;
		}
	}

	cout << dp[s.size()];

	return 0;
}