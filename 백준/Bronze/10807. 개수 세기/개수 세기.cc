#include <iostream>


using namespace std;
int main() {

	int count = 0;
	int n, v;
	cin >> n;
	int arr[101];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];	
	}

	cin >> v;

	for (int i = 0; i < n; i++) {
		if (arr[i] == v) {
			count += 1;
		}
	}
	cout << count;
}
