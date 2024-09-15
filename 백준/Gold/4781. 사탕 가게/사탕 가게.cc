#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int dp[10001];
int cal_array[50000];
int money_array[50000];

int t;

int candy;
float money;
//상근이가 돈 m을 가지고 구매할 수 있는 가장 높은 칼로리를 출력한다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		memset(dp, 0, sizeof(dp));
	
		cin >> candy >> money;
		int int_money = round(money * 100);
		if (candy == 0 && money == 0.00) break;

		for (int i = 1; i <= candy; i++) {
			int _cal;
			float _money;
			cin >> _cal >> _money;
			int _int_money = round(_money * 100);

			cal_array[i] = _cal;
			money_array[i] = _int_money;
		}
		dp[0] = 0;
		for (int i = 1; i <= candy; i++) {
			for (int j = money_array[i]; j <= int_money; j++) {
				dp[j] = max(dp[j], dp[j - money_array[i]] + cal_array[i]);
			}
		}

		cout << dp[int_money] << "\n";

	}

	return 0;
}