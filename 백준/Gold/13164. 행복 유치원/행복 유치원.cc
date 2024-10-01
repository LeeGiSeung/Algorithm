#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n, k;
vector<int> v;
vector<int> li;
int result = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}


	for (int i = 1; i < v.size(); i++) {
		li.push_back(v[i] - v[i - 1]);
	}

	sort(li.begin(), li.end());

	for (int i = 0; i < n-k; i++) {
		result += li[i];
	}

	cout << result;

	return 0;
}