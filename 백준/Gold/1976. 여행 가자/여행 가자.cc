#include <iostream>
#include <vector>
using namespace std;

int city[20000];

int n, m;

int find(int x) {
	//자기 자신이 최상위 노드일 경우 x return;
	if (city[x] == x) return x;
	return city[x] = find(city[x]);
}

void _union(int x, int y) {
	int _x = find(x);
	int _y = find(y);
	//_x가 더 작을경우 _x가 최상위 노드가됨
	if (_x < _y) {
		city[_y] = _x;
	}
	else {
		city[_x] = _y;
	}
}

bool get_find(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a == b) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		city[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;	
			if (a == 1) {
				_union(i, j);
			}
		}
	}

	int top = 0;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		a--;
		if (i == 0) top = find(a);
		else {
			if (!get_find(top, a)) {
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES";

	return 0;
}