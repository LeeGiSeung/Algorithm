#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define red 1
#define blue 2

using namespace std;

int k, v, e;
vector<int> g[200001];
int color[200001] = { 0 };

void coloring(int start) {
	queue<int> q;
	q.push(start);
	int c = red;
	color[start] = c;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (color[now] == red) {
			c = blue;
		}
		else if (color[now] == blue) {
			c = red;
		}

		for (int i = 0; i < g[now].size(); i++) {
			if (!color[g[now][i]]) {
				color[g[now][i]] = c;
				q.push(g[now][i]);
			}
		}

	}
}

void check() {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			if (color[i] == color[g[i][j]]) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> v >> e;
		for (int j = 1; j <= v; j++) {
			g[j].clear();
			color[j] = 0;
		}
		for (int j = 0; j < e; j++) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for (int j = 1; j <= v; j++) {
			if (!color[j]) {
				coloring(j);
			}
		}
		check();
	}
	

	return 0;
}
