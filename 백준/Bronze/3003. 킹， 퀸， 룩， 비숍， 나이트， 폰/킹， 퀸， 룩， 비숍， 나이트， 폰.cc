#include <iostream>
using namespace std;

int chess[6] = { 1,1,2,2,2,8 };
int input[6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 6; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < 6; i++) {
		if (input[i] > chess[i]) {
			cout << chess[i] - input[i] << " ";
		}
		else if (input[i] < chess[i]) {
			cout << chess[i] - input[i] << " ";
		}
		else {
			cout << 0 << " ";
		}
	}

	return 0;
}