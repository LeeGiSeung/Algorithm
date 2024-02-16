#include <iostream>
#include <deque>
#include <sstream>
#include <vector>
#include <string>
#define MAX 9999

using namespace std;

int MaxNumber = 0;
int n;
int v[500][500];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				v[i][j] = v[i - 1][0] + v[i][j];
			}
			else if (i == j) {
				v[i][j] = v[i - 1][j - 1] + v[i][j];
			}
			else {
				v[i][j] = max(v[i - 1][j - 1]+v[i][j], v[i-1][j]+v[i][j]);
			}
			MaxNumber = max(v[i][j], MaxNumber);
		}

	}

	cout << MaxNumber;

    return 0;
}