#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;
vector<pair<int, int>> v;

int n;
//최고 일수
int m = 0;
int result = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ b,a });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		//출연일 추가
		pq.push(v[i].second);
		if (pq.size() > v[i].first) {
			pq.pop();
		}
	}

	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}

	cout << result;
	return 0;

}