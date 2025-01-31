#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

string a, b, c, d;

long long result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c >> d;

	string ab = a + b;
	string cd = c + d;

	result = stoll(ab) + stoll(cd);

	cout << result;


	return 0;
}