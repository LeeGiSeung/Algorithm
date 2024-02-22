#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;
vector<int> ary;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, count = 1;
	long long result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ary.push_back(a);
	}

	sort(ary.begin(), ary.end());

	for (int i = 0; i < n; i++) {
		result += abs(ary[i] - (i + 1));
	}

	cout << result;

	return 0;

}