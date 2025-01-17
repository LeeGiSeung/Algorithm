#include <iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		while (a--) {
			cout << "=";
		}
		cout << "\n";
	}

	return 0;
}