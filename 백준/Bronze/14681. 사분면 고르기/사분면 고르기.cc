#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <string>

using namespace std;

int main() {
	int X, Y = 0;

	cin >> X;
	cin >> Y;

	if (X > 0 && Y > 0) {
		cout << 1;
	}
	else if (X > 0 && Y < 0) {
		cout << 4;
	}
	else if (X < 0 && Y < 0) {
		cout << 3;
	}
	else if (X < 0 && Y>0) {
		cout << 2;
	}

	return 0;
}