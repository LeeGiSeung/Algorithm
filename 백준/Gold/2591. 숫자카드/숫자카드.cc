#include <iostream>
using namespace std;

int dp[41];
char ch[41];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[0] = 1;

	//1부터 34까지 수가 적힌 카드
	//숫자가 34를 넘기면 안된다는 뜻
	//34가 넘기 전까지는 조합이 가능하다.

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		ch[i + 1] = s[i];
	}

	for (int i = 1; i <= s.size(); i++) {

		int k = ch[i] - '0';

		if (k != 0) {
			dp[i] = dp[i - 1];
		}

		if (i >= 2) {
			int x = (ch[i - 1] - '0') * 10 + k;
			if ( x >= 10 && x <= 34) {
				dp[i] = dp[i - 2] + dp[i];
			}
		}
	}

	cout << dp[s.size()];

	return 0;
}