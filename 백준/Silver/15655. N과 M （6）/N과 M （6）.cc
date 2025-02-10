#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<int> v;

bool check[9];

void solve(int _index, int _count) {
	//m개씩 말하면됨
	if (_count == m) {
		for (int i = 0; i < n; i++) {
			if (check[i] == true) {
				cout << v[i]<<" ";
			}
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = _index; i < n; i++) {
			if (check[i]) continue;
			check[i] = true;
			solve(i + 1, _count + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	solve(0, 0);

	return 0;
}