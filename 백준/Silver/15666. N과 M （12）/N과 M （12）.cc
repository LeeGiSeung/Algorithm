#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int number[10001] = { 0 };
bool visited[100001] = { 0 };
vector<int> ary;

int n, m = 0;

void back(int cnt, int num) {

	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << number[i] << " ";
		}
		cout << "\n";
		return;
	}

	int prevnum = -1;

	for (int i = num; i < n; i++) {
		if (prevnum != ary[i]) {

			number[cnt] = ary[i];

			prevnum = ary[i];

			back(cnt + 1, i);

		}

	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	ary.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> ary[i];
	}

	sort(ary.begin(), ary.end());
	back(0, 0);

	return 0;


}