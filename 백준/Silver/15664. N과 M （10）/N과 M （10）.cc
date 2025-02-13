#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> v;
int arr[9];
bool check[9];

int n, m;

void solve(int _idx, int _count) {
	if (_count == m) {
		for (int i = 0; i < _count; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else {
		int fast = -1;
		for (int i = _idx; i < n; i++) {
			if (check[i]) continue;
			//이전이랑 같은 숫자이면 continue;
			if (v[i] == fast) continue;

			check[i] = true;
			fast = v[i];
			arr[_count] = v[i];
			solve(i , _count + 1);
			check[i] = false;

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

	solve(0, 0);

	return 0;
}