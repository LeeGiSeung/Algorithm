#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
vector<int> v;
long long dp[100010][3];
long long map[100010][3];
int testcase = 1;
int mi;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (true) {
		memset(dp, 0, sizeof(dp));
		memset(map, 0, sizeof(map));
		int n;
		cin >> n;
		//0을 입력받으면 중지
		if (n == 0) break;

		for (int i = 0; i < 3; i++) {
			dp[0][i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> map[i][j];
			}
		}

		dp[1][0] = 100000;
		dp[1][1] = map[1][1];
		dp[1][2] = map[1][2] + dp[1][1];

		//1층에서 n층까지
		for (int i = 2; i <= n; i++) {

			dp[i][0] = min(dp[i - 1][0] + map[i][0], dp[i - 1][1] + map[i][0]);
			dp[i][1] = min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0] }) + map[i][1];
			dp[i][2] = min({ dp[i - 1][1],dp[i - 1][2], dp[i][1] }) + map[i][2];
			
		}

		cout << testcase << ". " << dp[n][1]<<"\n";
		testcase++;


	}

	return 0;
}