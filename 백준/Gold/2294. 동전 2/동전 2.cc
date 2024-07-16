#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[10001] = { 0, };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//입력
	int n,k;
	cin >> n>>k; //n개의 동전, k원을 만들어야 한다.
	vector<int>money(n+1);
	for (int i = 1; i <= n; i++) cin >> money[i];

	//문제 해결
	for (int i = 1; i <= k; i++) dp[i] = 10001; //최솟값을 구하기 위함

	for (int i = 1; i <= n; i++) { // money[i] 동전을 가지고
		for (int j = money[i]; j <= k; j++) { // 최솟값을 만들 수 있으면 갱신
			dp[j] = min(dp[j], dp[j - money[i]] + 1);
		}
	}

	//결과 출력
	if (dp[k] == 10001) cout << -1 << '\n';
	else cout << dp[k] << '\n';
}