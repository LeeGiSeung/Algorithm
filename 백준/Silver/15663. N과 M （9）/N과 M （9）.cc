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

int n, m;

void back(int x) {
	
	if (x == m) {
		for (int i = 0; i < m; i++) {
			cout << number[i] <<" ";
		}
		cout << "\n";
	}

	int prevnum = -1;

	for (int i = 0; i < n; i++) {
		if (!visited[i] && prevnum != ary[i]) {
			visited[i] = true;
			number[x] = ary[i];
			prevnum = ary[i];
			back(x + 1);
			visited[i] = false;
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
	back(0);

	return 0;


}