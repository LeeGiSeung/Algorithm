#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n, m;

vector<int> v;

int result = 1;
int lesstape;
int a;
int start;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	start = v[0];

	for (int i = 1; i < n; i++) {
		if (m <= v[i] - start) {
			result++;
			start = v[i];
		}
	}

	cout << result;

	return 0;
}