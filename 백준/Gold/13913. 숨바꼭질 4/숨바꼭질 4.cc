#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
struct DATA {
	int cur;
	vector<int> a;
	int time;
};
int n, k;
bool check[100001];
bool flag = false;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int start = 0, end = 0;
	cin >> n >> k;
	start = n;
	end = k;

	if (end >= start) {
		vector<int> v;
		v.push_back(start);
		queue <DATA> q;
		q.push({ start,v });
		while (!q.empty()) {
			int cur = q.front().cur;
			vector<int> a = q.front().a;
			int ti = q.front().time;
			q.pop();
			//도착 했으면
			if (cur == end) {
				cout << ti << "\n";
				if (!flag) {
					for (int i = 0; i < a.size(); i++) {
						cout << a[i] << " ";
					}
				}
				else {
					for (int i = a.size() - 1; i >= 0; i--) {
						cout << a[i] << " ";
					}
				}
				return 0;
			}
			//+ - *2
			for (int i = 0; i < 3; i++) {
				int check_int;
				vector<int> ca = a;
				if (i == 0) {
					check_int = cur * 2;
					if (check_int > 100001 || check[check_int]) continue;
				}
				else if (i == 1) {
					check_int = cur + 1;
					if (check_int > 100001 || check[check_int]) continue;
				}
				else if (i == 2) {
					check_int = cur - 1;
					if (check_int < 0 || check[check_int]) continue;
				}
				check[check_int] = true;
				ca.push_back(check_int);
				q.push({ check_int, ca , ti + 1 });
			}
		}
	}

	else {
		cout << start - end << "\n";
		for (int i = start; i >= end; i--) {
			cout << i << " ";
		}
	}

	return 0;
}