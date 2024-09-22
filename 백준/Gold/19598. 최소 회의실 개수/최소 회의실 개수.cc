#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
//시작 시간과 끝나는 시간은 231−1보다 작거나 같은 자연수 또는 0이다.
int n;

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int,int>> v;

int result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int st, en;
		cin >> st >> en;
		v.push_back({ st,en });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (pq.empty()) {
			pq.push(v[i].second);
			result++;
		}
		else {
			//한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다.
			if (pq.top() > v[i].first) {
				pq.push(v[i].second);
				result++;
			}
			else if (pq.top() <= v[i].first) {
				pq.pop();
				pq.push(v[i].second);
			}
		}
	}

	cout << result;

	return 0;
}