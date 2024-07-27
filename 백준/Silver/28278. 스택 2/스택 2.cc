#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

#define endl "\n"

using namespace std;
int n;
stack<int> s;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a;
		if (a == 1) {
			cin >> b;
			s.push(b);
		}
		else if (a == 2) {
			if (s.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (a == 3) {
			cout << s.size() << endl;
		}
		else if (a == 4) {
			if (s.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (a == 5) {
			if (!s.empty()) {
				cout << s.top() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
	return 0;
}
