#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
string s, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> t;

	int t_index = t.size() - 1;

	while (s.size() < t.size()) {
		if (t[t_index] == 'A') {
			t.pop_back();
		}
		else {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
		t_index -= 1;
	}

	if (s == t) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}