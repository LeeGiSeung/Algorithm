#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int a;

int main() {

	int result = 0;

	for (int i = 0; i < 5; i++) {
		cin >> a;
		result += a;
	}

	cout << result;

	return 0;
}