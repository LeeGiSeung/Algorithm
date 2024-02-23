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
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
bool visit[100005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;

	pq.push(make_pair(0, n));

	while (!pq.empty()) {
		int time = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		visit[x] = 1;

		if (x == k) {
			printf("%d", time);
			break;
		}

		if (x - 1 >= 0 && !visit[x - 1])
			pq.push(make_pair(time + 1, x - 1));
		if (x + 1 <= 100000 && !visit[x + 1])
			pq.push(make_pair(time + 1, x + 1));
		if (x * 2 <= 100000 && !visit[x * 2])
			pq.push(make_pair(time, x * 2));
	}


	return 0;

}