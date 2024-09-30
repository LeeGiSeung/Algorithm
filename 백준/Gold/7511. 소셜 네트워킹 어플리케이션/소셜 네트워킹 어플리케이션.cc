#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int t, n, k, a, b, m, u, v;

int user[10000001];

int find(int x) {
	if (x == user[x]) return x;
	return user[x] = find(user[x]);
}

void _union(int x, int y) {
	x = find(x);
	y = find(y);
	if (x > y) {
		user[x] = y;
	}
	else {
		user[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int z = 1; z <= t; z++) {
		vector<pair<int, int>> uv_list;
		vector<int> result;

		memset(user, 0, sizeof(user));

		cin >> n;
		for (int i = 0; i < n; i++) {
			user[i] = i;
		}

		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			_union(a, b);
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			uv_list.push_back({ u,v });
		}
		cout << "Scenario " << z << ":" << "\n";
		for (int i = 0; i<uv_list.size(); i++) {
			if (find(uv_list[i].first) == find(uv_list[i].second)) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		cout << "\n";
	}

	return 0;
}