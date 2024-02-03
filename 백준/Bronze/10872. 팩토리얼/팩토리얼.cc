#include <iostream>


using namespace std;
int main() {
	long result = 1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		result = result * i;
	}
	cout << result;
}