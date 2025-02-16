#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a < b) {
			cout << "NO BRAINS" << "\n";
		}
		else {
			cout << "MMM BRAINS" << "\n";
		}
	}

	return 0;
}