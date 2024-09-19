#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
vector<int> v[2000];
int check[2000];
void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

bool flag = 0;

void dfs(int a, int count) {
	if (count >= 4) {
		flag = 1;
		return;
	}

	check[a] = true;

	for (int i = 0; i < v[a].size(); i++) {
		if (check[v[a][i]] == false) {
			dfs(v[a][i], count + 1);
			check[v[a][i]] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(check, 0, sizeof(check));

	input();

	for (int i = 0; i < n; i++) {
		if (check[i] == false) {
			dfs(i, 0);
			check[i] = false;
		}

		if (flag) {
			cout << 1;
			return 0;
		}

	}
	cout << 0;

	return 0;
}