#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int a, b, c;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;

	if (a * 1 + b * 2 + c * 3 >= 10) {
		cout << "happy";
	}
	else {
		cout << "sad";
	}

	return 0;
}