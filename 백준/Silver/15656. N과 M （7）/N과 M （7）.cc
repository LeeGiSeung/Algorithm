#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;

bool check[8][8];

void solve(int _count) {
	if (_count == m) {
		for (int j = 0; j < _count; j++) {
			for (int i = 0; i < n; i++) {
				if (check[j][i] == true) {
					cout << v[i] << " ";
				}
			}
		}
		cout << "\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			if (check[_count][i]) continue;
			check[_count][i] = true;
			solve(_count + 1);
			check[_count][i] = false;
		}
	}
}

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	solve(0);

	return 0;
}