#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

int n, m, a, k;
vector<int> v;
int c = 2000000000;
int s = 0;
int e = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	while (s < n && e<n) {
		k = v[e] - v[s];

		if (k < m) e++;
		else {
			s++;
			c = min(c, k);
		}
	}

	cout << c;

	return 0;
}
