#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n = 0;
	int c = 0;
	int count = 99;
	cin >> n;


	if (n < 100) {
		cout << n;
	}
	else {
		for (int i = 100; i <= n; i++) {
			int one, ten, hun;
			one = i % 10;
			ten = (i / 10) % 10;
			hun = i / 100;


			if ((hun - ten) == (ten - one)) {
				count++;
			}

		}

		cout << count;
	}

		

	return 0;
	}
