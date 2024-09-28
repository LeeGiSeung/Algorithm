#include <iostream>
using namespace std;

int n, m, k;

int map[301][301];

int result = 0;
int sum(int x, int y, int xx, int yy) {
	int result = 0;
	for (int i = x; i <= xx; i++) {
		for (int j = y; j <= yy; j++) {
			result += map[i][j];
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	
	cin >> k;

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << sum(a, b, c, d)<<"\n";
	}

	return 0;
}