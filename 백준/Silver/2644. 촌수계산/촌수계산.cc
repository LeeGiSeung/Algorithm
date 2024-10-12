#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int result = 999999;
vector<int> v[101];

int n;
int s, e;
int a, b;
int m;

int chon[101];
bool check[101];

void bfs(int x) {
	queue<pair<int, int>> q;
	q.push({ x,0 });
	check[x] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int count = q.front().second;
		q.pop();

		if (cur == e) {
			result = count;
			cout << result;
			break;
		}
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			int next_count = count + 1;
			if (!check[next]) {
				check[next] = true;
				q.push({ next,next_count });
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		chon[i] = i;
	}
	cin >> s >> e;
	cin >> m;
	for (int i = 0; i < m; i++) {
		//a는 b의 부모
		cin >> a >> b;
		v[b].push_back(a);
		v[a].push_back(b);
	}

	bfs(s);

	if (result == 999999) {
		cout << -1;
	}

	return 0;
}