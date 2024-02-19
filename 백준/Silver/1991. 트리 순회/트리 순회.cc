#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int n;
int ary[50][2];

void preorder(int N) {
	if (N == -1) return;
	cout << (char)(N + 'A');
	preorder(ary[N][0]);
	preorder(ary[N][1]);
}

void inorder(int N) {
	if (N == -1) return;
	inorder(ary[N][0]);
	cout << (char)(N + 'A');
	inorder(ary[N][1]);
}

void postorder(int N) {
	if (N == -1) return;
	postorder(ary[N][0]);
	postorder(ary[N][1]);
	cout << (char)(N + 'A');
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char m, l, r;
		cin >> m >> l >> r;
		m = m - 'A';
		if (l == '.') {
			ary[m][0] = -1;
		}
		else {
			ary[m][0] = l - 'A';
		}
		if (r == '.') {
			ary[m][1] = -1;
		}
		else {
			ary[m][1] = r - 'A';
		}
	}

	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);

	return 0;

}