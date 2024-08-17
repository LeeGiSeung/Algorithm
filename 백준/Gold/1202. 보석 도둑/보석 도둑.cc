#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;

vector<pair<int,int>> jewelry;
vector<int> bag;
priority_queue<int, vector<int>, less<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		jewelry.push_back({ a,b });
	}

	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		bag.push_back(a);
	}

	int idx = 0;
	long long sum = 0;

	sort(jewelry.begin(), jewelry.end());
	sort(bag.begin(), bag.end());

	for (int i = 0; i < k; i++) {
		while (idx < n && bag[i] >= jewelry[idx].first) {
			pq.push(jewelry[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;

	return 0;
}