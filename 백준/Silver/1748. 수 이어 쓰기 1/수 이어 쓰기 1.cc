#include <iostream>
using namespace std;

int n;

long long result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if (n < 10) {
		cout << n;
		return 0;
	}

	for (int i = 1; i <= n; i*=10) {
		result += n - i + 1;
	}

	cout << result;

	return 0;
}