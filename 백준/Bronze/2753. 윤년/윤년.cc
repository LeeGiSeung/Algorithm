#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <string>

using namespace std;

int main() {
	int Year;
	cin >> Year;
	if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}


	return 0;
}