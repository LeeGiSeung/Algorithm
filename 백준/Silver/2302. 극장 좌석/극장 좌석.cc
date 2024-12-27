#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, m, a;
bool check[41];
int dp[41];
int result = 1;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> n;
	cin >> m;

	while (m--) {
		cin >> a;
		check[a] = true;
	}

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int start = 1;

	for (int i = 1; i <= n; i++) {
		//vip석을 만났을 경우
		if (check[i] == true) {
			//교환 가능한 자리에 해당하는 경우의 수를 기존 답에 곱해줌
			v.push_back(dp[i - start]);
			start = i + 1;
		}
	}

	v.push_back(dp[n - start + 1]);

	//result += result * dp[(n - start)];
	
	for (int i = 0; i < v.size(); i++) {
		result *= v[i];
	}

	cout << result;

	return 0;
}