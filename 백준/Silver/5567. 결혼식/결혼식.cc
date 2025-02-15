#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

vector<int> v[501];
bool check[501];
int result = 0;

int n, m;

void solve(int x) {
	queue<pair<int,int>> q;
	q.push({x,0});
	check[x] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int count = q.front().second;
		q.pop();

		//cout << cur << endl;

		result++;

		for (int i = 0; i < v[cur].size(); i++) {
			if (check[v[cur][i]]) continue;
			if (count + 1 > 2) continue;
			check[v[cur][i]] = true;
			q.push({ v[cur][i], count + 1 });
		}

	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	solve(1);

	cout << result - 1;

	return 0;
}