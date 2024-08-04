#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;
int n;

stack<int> building;

vector<int> re;
long long r = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {

		int a;
		cin >> a;


		while (!building.empty() && a >= building.top()) {
			building.pop();
		}

		if (!building.empty()) {
			r += building.size();
		}

		building.push(a);
	
	}

	cout << r;

	return 0;
}
