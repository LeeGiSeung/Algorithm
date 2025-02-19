#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

vector<int> v;
bool check[15];
int a;

void solve(int _index, int _count) {
	if (_count == 6) {
		for (int i = 0; i < a; i++) {
			if (check[i]) {
				cout << v[i] << " ";
			}
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = _index; i < a; i++) {
			if (check[i]) continue;
			check[i] = true;
			solve(i + 1, _count + 1);
			check[i] = false;
		}
	}
}

int main() {

	while (true) {

		v.clear();
		memset(check, false, sizeof(check));

		cin >> a;
		if (a == 0) break;

		for (int i = 0; i < a; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

		solve(0, 0);
		cout << "\n";
	}

	return 0;
}