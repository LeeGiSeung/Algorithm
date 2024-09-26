#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;

vector<int> box;
vector<int> crain;

int ti = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		crain.push_back(a);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		box.push_back(a);
	}

	sort(crain.begin(), crain.end());
	sort(box.begin(), box.end());

	if (box.back() > crain.back()) {
		cout << -1;
		return 0;
	}

	while (!box.empty()) {
		ti++;
		for (int i = crain.size()-1; i >= 0; i--) {
			for (int j = box.size() -1; j >= 0; j--) {
				if (crain[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
	}

	cout << ti;

	return 0;
}