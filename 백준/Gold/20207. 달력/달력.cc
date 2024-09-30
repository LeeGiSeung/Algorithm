#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<pair<int, int>> v;

int map[1000][366];

int min_s = 10000;
int max_t = 0;
int max_z = 0;

int n;

int s, t;

int result = 0;

bool compare(const pair<int,int> &a, const pair<int,int> &b) {
	//x는 같은데
	if (a.first != b.first) {
		return a.first < b.first;
	}
	else {
		return (a.second - a.first) > (b.second - a.first);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//일정은 시작날짜와 종료날짜를 포함한다.
	//시작일이 가장 앞선 일정부터 차례대로 채워진다.
	//시작일이 같을 경우 일정의 기간이 긴 것이 먼저 채워진다.
	//일정은 가능한 최 상단에 배치된다.
	//일정 하나의 세로의 길이는 1이다.
	//하루의 폭은 1이다.

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		v.push_back({ s,t });
	}

	sort(v.begin(), v.end(), compare);
	//cout << endl;
	for (int i = 0; i < v.size(); i++) {
		//cout << s << " " << t << endl;
		s = v[i].first;
		t = v[i].second;

		//다른 종이를 붙일 타이밍
		if (max_t + 1 < s && i != 0) {
			//cout << 1 << endl;
			result += (max_t - min_s + 1) * max_z;
			min_s = 10000;
			max_t = 0;
			max_z = 0;
		}

		for (int z = 1; z <= n; z++) {
			int flag = 0;
			for (int q = s; q <= t; q++) {
				if (map[z][q] == 1) {
					flag = 1;
					break;
				}
			}
			//일정이 칠해져있지 않으면 추가함
			if (flag == 0) {
				for (int q = s; q <= t; q++) {
					map[z][q] = 1;
					min_s = min(q, min_s);
					max_t = max(q, max_t);
					max_z = max(z, max_z);
				}
				break;
			}
		}
	}

	result += (max_t - min_s + 1) * max_z;

	cout << result;

	return 0;
}