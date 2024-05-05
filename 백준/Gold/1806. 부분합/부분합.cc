#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int start = 0;
	int end = 0;
	int cnt = 100000000;
	int sum = 0;

	while (start <= end) {
		if (sum >= s) {
			cnt = min(cnt, end - start);
			sum -= v[start];
			start++;
		}
		else if (end == n) break;
		else {
			sum += v[end++];
		}
	}

	if (cnt == 100000000)
		cout << 0;
	else {
		cout << cnt;
	}

	return 0;
}