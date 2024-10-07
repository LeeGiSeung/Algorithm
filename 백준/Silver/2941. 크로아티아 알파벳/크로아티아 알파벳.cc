#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

string list[8] = { "dz=","c=","c-", "d-", "lj", "nj", "s=", "z=" };
int ct = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int idx;

	cin >> s;

	for (int i = 0; i < 8; i++) {
		while (true) {
			idx = s.find(list[i]);
			if (idx == -1) {
				break;
			}		
			s.replace(idx, list[i].length(), "#");
		}
	}

	cout << s.length();

	return 0;
}