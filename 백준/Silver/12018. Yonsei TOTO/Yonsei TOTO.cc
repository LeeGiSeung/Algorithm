#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n, m;
int result = 0;
//index는 수업 번호이고 각 수업마다 신청한 마일리지를 push_back
vector<int> mileage[100];
//index는 수업 번호이고 각 수업의 제한 수강인원
vector<pair<int,int>> limitstudent[100];

vector<int> list;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		//a 수강 신청한 인원
		//b 수강 신청 가능한 인원
		int a, b;
		cin >> a >> b;
		limitstudent[i].push_back({a,b});
		for (int j = 0; j < a; j++) {
			int z;
			cin >> z;
			mileage[i].push_back(z);
		}
	}

	for (int i = 0; i < n; i++) {
		sort(mileage[i].begin(), mileage[i].end(),greater<int>());
	}

	for (int i = 0; i < n; i++) {
		int index = limitstudent[i][0].first - limitstudent[i][0].second;
		if (index < 0) {
			list.push_back(1);
		}
		else {
			list.push_back(mileage[i][(limitstudent[i][0].first) - index - 1]);
		}
	}

	sort(list.begin(), list.end());

	int list_index = 0;
	while (true) {
		if (list_index >= list.size()) break;
		if (m - list[list_index] >= 0) {
			m -= list[list_index];
			result++;
			list_index++;
		}
		else {
			break;
		}
	}

	cout << result;

	return 0;
}