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
#include <map>
#include <cstring>

using namespace std;
int n, a, b;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int min, young;
		cin >> min >> young;
		arr.push_back(min - young);
	}
	sort(arr.begin(), arr.end());
	if (N % 2 == 1) {
		cout << 1;
	}
	else {
		cout << arr[N / 2] - arr[N / 2 - 1] + 1;
	}

}