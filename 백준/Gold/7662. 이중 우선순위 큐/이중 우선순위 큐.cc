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
#include <map>

using namespace std;
int T;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;

	for (int j = 0; j < T; j++) {
		priority_queue<int, vector<int>, greater<int>> min_queue;
		priority_queue<int, vector<int>, less<int>> max_queue;
		map<int, int> cnt;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			string DI;
			int n;
			cin >> DI >> n;
			if (DI == "I") {
				min_queue.push(n);
				max_queue.push(n);
				cnt[n]++;
			}
			else if (DI == "D") {
				if (n == 1 && !max_queue.empty()) {
					cnt[max_queue.top()]--;
					max_queue.pop();
				}
				else if (n == -1 && !min_queue.empty()) {
					cnt[min_queue.top()]--;
					min_queue.pop();
				}
			}
			while (!min_queue.empty() && cnt[min_queue.top()] == 0) {
				min_queue.pop();
			}

			while (!max_queue.empty() && cnt[max_queue.top()] == 0) {
				max_queue.pop();
			}
		}
		if (max_queue.empty() || min_queue.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			cout << max_queue.top() << " " << min_queue.top() << "\n";
		}
	}
	return 0;

}