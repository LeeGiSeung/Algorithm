#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 1000001

using namespace std;
int a, b;


int bfs(int start,int result) {
	deque<pair<long long, long long>> ary;
	ary.push_back(make_pair(start,1));
	while(!ary.empty()){
		pair<long, long> now = ary.front();
		ary.pop_front();
		//cout << now.first << now.second << "\n";
		if (now.first == result) {
			return now.second;
		}
		if (now.first * 2 <= result) {
			ary.push_back(make_pair(now.first * 2, now.second + 1));
		}
		if (now.first * 10 + 1 <= result) {
			ary.push_back(make_pair(now.first * 10 + 1, now.second + 1));
		}
	}
	return -1;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	cout<<bfs(a,b);

    return 0;
}