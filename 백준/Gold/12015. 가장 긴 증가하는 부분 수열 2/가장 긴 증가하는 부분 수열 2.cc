#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> dp;
	for (auto& x : v) cin >> x;
	dp.push_back(v[0]);
	for (int i = 1; i < N; i++) {
		if (dp.back() < v[i]) dp.push_back(v[i]);
		else {
			auto p = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
			dp[p] = v[i];
		}
	}
	cout << dp.size();
}