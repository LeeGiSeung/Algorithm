#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 9

using namespace std;
int n, m;
int number[MAX] = { 0, };
vector<int> v;
bool visited[MAX] = { 0, };

void back(int cnt) {
	if (m == cnt) {
		for (int i = 0; i < m; i++) {
			cout << number[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
		if (!visited[i]) {

			{
				visited[i] = true;
				number[cnt] = v[i];
				back(cnt + 1);
				visited[i] = false;
			}
		}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	back(0);

	return 0;
}