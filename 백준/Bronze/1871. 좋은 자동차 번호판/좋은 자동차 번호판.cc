#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n, m, k;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (n--) {
		string s;
		cin >> s;
		int _index;
		string a = s.substr(0, s.find("-"));
		string b = s.substr(s.find("-") + 1, s.size());

		int _a;
		int _b;
		int x = 0;
		int z = 0;

		for (int i = 0; i < a.size(); i++) {
			z += (a[i] - 'A') * pow(26,a.size() - 1 - i);
		}
		//cout << z << endl;
		//cout << z << endl;
		for (int i = 0; i < b.size(); i++) {
			x += (b[i] - '0') * pow(10,b.size() - 1 - i);
		}
		//cout << x << endl;
		if (abs(x - z) <= 100) {
			cout << "nice" << "\n";
		}
		else {
			cout << "not nice" << "\n";
		}

	}

	return 0;
}