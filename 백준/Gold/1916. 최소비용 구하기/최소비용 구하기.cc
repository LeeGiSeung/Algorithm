#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
int dp[1001];
vector<pair<int, int>> ary[1001];

void bfs(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int current = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cost > dp[current]) {
			continue;
		}
		for (int i = 0; i < ary[current].size(); i++) {
			int next = ary[current][i].first;
			int next_cost = dp[current] + ary[current][i].second;

			if (next_cost < dp[next]) {
				dp[next] = next_cost;
				pq.push({ next_cost,next });
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		ary[x].push_back({ y,z });
	}
	int go, goal;
	cin >> go >> goal;
	fill_n(dp, 1001, 987654321);
	dp[go] = 0;
	bfs(go);

	cout << dp[goal];

	return 0;

}