#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 1000001

using namespace std;
int n, a, b;
vector<int>v[MAX];
int result[MAX];

void bfs(int start) {
	deque<int> q;
	q.push_back(start);
	while (!q.empty()) {
		a = q.front();
		q.pop_front();
		for (int i = 0; i < v[a].size(); i++) {
			int chi = v[a][i];
			if (result[a] == chi)continue;
			q.push_back(chi);
			result[chi] = a;
		}
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs(1);

	for (int i = 2; i <= n; i++) {
		cout << result[i] << "\n";
	}

    return 0;
}