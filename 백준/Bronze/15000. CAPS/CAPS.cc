#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		s[i] = s[i] - 32;
	}

	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
	}

	return 0;
}