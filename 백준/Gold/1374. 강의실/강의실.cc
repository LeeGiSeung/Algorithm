#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

vector<pair<int, int>> v;

int n;

int result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int number, start, end;
		cin >> number >> start >> end;
		v.push_back({ start,end });
	}

	sort(v.begin(), v.end());

	int room = 0;

	for (int i = 0; i < v.size(); i++) {
		if (pq.empty()) {
			room++;
			pq.push(v[i].second);
		}
		else {
			if (pq.top() > v[i].first) {
				room++;
				pq.push(v[i].second);
			}
			else {
				if (pq.top() <= v[i].first) {
					pq.pop();
					pq.push(v[i].second);
				}
			}
		}
	}

	cout << room;

	return 0;
}