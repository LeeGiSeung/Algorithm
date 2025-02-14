#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
set<int> v;
int check[8];


void solve(int _count) {
	if (_count == m) {

		for (int i = 0; i < _count; i++) {
			cout << check[i] << " ";
		}

		cout << "\n";
		return;
	}
	else {
		for (auto cur : v) {
			
			check[_count] = cur;
			solve(_count + 1);
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.insert(a);
	}

	solve(0);

	return 0;
}