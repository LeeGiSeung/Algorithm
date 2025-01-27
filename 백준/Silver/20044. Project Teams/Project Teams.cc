#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n;
int a;

vector<int> v;
vector<int> list;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n * 2; i++) {
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int result = 300000;

	for (int i = 0; i < n; i++) {
		result = min(result, v[i] + v[v.size() - 1 - i]);
	}

	cout << result;

	return 0;
}