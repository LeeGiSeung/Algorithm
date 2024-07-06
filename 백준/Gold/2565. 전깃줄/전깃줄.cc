#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>

#define endl "\n"

using namespace std;
vector<pair<int, int>> v;
int dp[501];
int res = 0;

int t, n;

void dp_GO() {
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(dp[i], res);
	}
	cout << n-res << endl;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	dp_GO();

	return 0;
}