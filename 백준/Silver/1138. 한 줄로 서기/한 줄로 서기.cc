#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


int main(void) {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, left;
	int people[11] = { 0 };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> left;
		for (int j = 0; j < n; j++) {
			if (left == 0 && people[j] == 0) {
				people[j] = i;
				break;
			}
			else if (people[j] == 0) {
				left--;
			}
		}
		
	}

	for (int i = 0; i < n; i++) {
		cout << people[i] << " ";
	}
		

	return 0;
	}
