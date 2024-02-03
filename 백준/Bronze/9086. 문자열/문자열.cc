#include <iostream>
#include <string>
using namespace std;



int main() {

	int n;
	string s;

	cin >> n;

	while (n--) {
		cin >> s;
		cout << s[0] << s[s.length() - 1] << '\n';
	}

	return 0;
}