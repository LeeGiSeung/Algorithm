#include <iostream>

using namespace std;

int x = 10;
int y = 10;
int result = 0;
bool map[111][111] = { false };

void black(int bx, int by) {
	for (int i = bx; i < bx + x; i++) {
		for (int j = by; j < by + y; j++) {
			if (0 <= i && i < 100 && 0 <= j && j < 100 && map[i][j] == false) {
				map[i][j] = true;
				result++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		black(a, b);
	}

	cout << result << "\n";

	return 0;
}