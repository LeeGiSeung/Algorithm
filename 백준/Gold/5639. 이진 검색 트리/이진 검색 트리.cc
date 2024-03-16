#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> v;

void go(int st, int en){
	if(st >= en) return;
	if(st == en-1){
		cout << v[st] << '\n';
		return;
	}
	int idx = st + 1;
	while(idx < en){
		if(v[st] < v[idx]) break;
		idx++;
	}
	go(st+1, idx);
	go(idx, en);
	cout << v[st] << '\n';
	return;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while(cin >> n){
		v.push_back(n);
	}
	go(0, v.size());
	return 0;
}