#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int count = 1;
	int a = 1;
	int e = n;

	while (e <= n && a<=n) {
		if (count == k && n % a == 0) {
			cout << a;
			return 0;
		}
		else if (count != k && n % a == 0) {
			count++;
			a++;
		}
		else {
			a++;
		}
	}

	cout << 0 << "\n";

	return 0;
}