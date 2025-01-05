#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n;

void solve(int _width, int _height, int _num) {
	if ((_width / _num) % 3 == 1 && (_height / _num) % 3 == 1) {
		cout << " ";
	}
	else {
		if (_num / 3 == 0) {
			cout << "*";
		}
		else {
			solve(_width, _height, _num / 3);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			solve(i, j, n);
		}
		cout << "\n";
	}

	return 0;
}