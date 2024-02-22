#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
deque<int> ary;
int n, x;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		ary.push_back(b);
	}
	cin >> x;
	sort(ary.begin(), ary.end());

	int l = 0, r = n - 1;
	int count = 0;

	while (1) {
		if (l >= r) {
			break;
		}
		int sum = ary[l] + ary[r];
		if (sum == x) {
			count++;
			l++;
			r--;
		}
		else if (sum < x) {
			l++;
		}
		else {
			r--;
		}
	}

	cout << count;

	return 0;

}