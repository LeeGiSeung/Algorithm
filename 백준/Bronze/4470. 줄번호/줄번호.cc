#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include <string>

using namespace std;



int main() {
	
	string input;
	int n = 0;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		getline(cin, input);
		cin.clear();
		cout << i + 1 << "." << " " << input << endl;
	}

	return 0;
}