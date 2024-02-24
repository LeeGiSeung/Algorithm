#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;
int n, m, b, a, height;
int minecraft[500][500];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int time = 2147000000;

	cin >> n >> m >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> minecraft[i][j];
		}
	}

	for (int k = 0; k <= 256; k++) {
		int sum = 0;
		int inventory = b;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//블록 놓기
				if (minecraft[i][j] < k) {
					sum += k - minecraft[i][j];
					inventory -= k - minecraft[i][j];
				}
				else if (minecraft[i][j] > k) {
					sum += (minecraft[i][j] - k) * 2;
					inventory += minecraft[i][j] - k;
				}
				else if (k == minecraft[i][j]) {
					continue;
				}
			}
		}

		if (inventory >= 0) {
			if (sum <= time) {
				time = sum;
				height = k;
			}
		}
	}

	cout << time<<" " << height;

	return 0;

}