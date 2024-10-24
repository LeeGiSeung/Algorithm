#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int n,a;
int v[1001];
bool check[1001];
bool come;
int result;
void bfs(int x) {
	queue<pair<int,int>> q;
	q.push({ x,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int count = q.front().second;
		q.pop();

		if (cur >= n) {
			come = true;
			result = count;
			return;
		}

		if (v[cur] == 0) continue;

		for (int i = 1; i <= v[cur]; i++) {
			if (cur + i > n) break;
			if (check[cur + i]) continue;
			check[cur + i] = true;
			q.push({ cur + i , count + 1});
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	bfs(1);

	if (come) {
		cout << result;
	}
	else {
		cout << -1;
	}

	return 0;
}