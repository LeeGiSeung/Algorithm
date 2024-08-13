#include <iostream>
#include <vector>

using namespace std;

int n = 0;
int m = 0;


int cost[101];
int bite[101];
int dp[101][10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sum_cost = 0;
	cin >> n >> m;

	//최대 비용은 비용은 정해져있음 이 비용중 가장 먼저 m에 과 똑같은 bite를 가진 비용울 출력하면됨

	for (int i = 1; i <= n; i++) {
		cin >> bite[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		sum_cost += cost[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum_cost; j++) {
			if (j - cost[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + bite[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= sum_cost; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			break;
		}
	}
	

	return 0;
}