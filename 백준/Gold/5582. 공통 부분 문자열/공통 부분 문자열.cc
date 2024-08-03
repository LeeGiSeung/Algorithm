#include <iostream>
#include <string>

using namespace std;

string s, t;
int dp[4003][4003] = { 0 };
int result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> t;

	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < t.length(); j++) {
			if(s[i] == t[j]) {
				dp[i][j] = 1;
				if (i >= 1 && j >= 1) {
					dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
				}
				result = max(result, dp[i][j]);
			}
		}
	}

	cout << result;

	return 0;
}