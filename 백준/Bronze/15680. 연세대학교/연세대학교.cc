#include <iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if (n == 0) {
		cout << "YONSEI";
	}
	else if (n == 1) {
		cout << "Leading the Way to the Future";
	}

	return 0;
}