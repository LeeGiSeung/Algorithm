#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int t, a;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//0.25 0.10 0.05 0.01
	int q = 25;
	int d = 10;
	int n = 5;
	int p = 1;

	cin >> t;

	while (t--) {
		cin >> a;
		cout << a / q << " ";
		a %= q;
		cout << a / d << " ";
		a %= d;
		cout << a / n << " ";
		a %= n;
		cout << a / p;
		a %= p;
		cout << "\n";
	}

	return 0;
}