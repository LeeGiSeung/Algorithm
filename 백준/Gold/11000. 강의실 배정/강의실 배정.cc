#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>

#define endl "\n"

using namespace std;
int n;
int result = 0;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> q;


int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	q.push(v[0].second);

	for (int i = 1; i < n; i++) {
		if (v[i].first >= q.top()) {
			q.pop();
			q.push(v[i].second);
		}
		else q.push(v[i].second);
	}

	cout << q.size() << endl;

	return 0;
}