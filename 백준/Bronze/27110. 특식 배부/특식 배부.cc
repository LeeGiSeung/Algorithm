#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n;
int a, b, c;

int result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> a >> b >> c;

	if (a < n) result += a;
	else result += n;

	if (b < n) result += b;
	else result += n;

	if (c < n) result += c;
	else result += n;

	cout << result;

	return 0;
}