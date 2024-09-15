#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t;

int coin[21];
int dp[100001];
int limit = 0;
int result = 0;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> coin[j];
		}
		cin >> limit;

		for (int j = 1; j <= n; j++) {
			for (int z = coin[j]; z <= limit; z++) {
				dp[z] = dp[z] + dp[z - coin[j]];
			}
		}

		//limit이 될때까지 coin안에 있는 동전들로 만들 수 있는 모든 방법의 수 출력
		cout << dp[limit] << "\n";
	}


	return 0;
}