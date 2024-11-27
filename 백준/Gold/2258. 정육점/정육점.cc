#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N, M;
int KG, COST;
int SUM_COST = 0;
int SUM_KG;
int HIGH_COST;
vector<pair<int, int>> v;
vector<pair<int, int>> v2;

bool CAN;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	//최소 비용을 계산하는 프로그램을 작성하시오.
	for (int i = 0; i < N; i++) {
		cin >> KG >> COST;
		v.push_back({ KG, COST });
	}
	//M만큼의 고기를 구매해야 한다.

	sort(v.begin(), v.end(), cmp);

	//COST 기준으로 정렬
	int before = 0;
	for (int i = 0; i < v.size(); i++) {
		if (SUM_KG < M) {
			if (before == v[i].second) {
				SUM_COST += v[i].second;
			}
			else {
				SUM_COST = v[i].second;
				before = v[i].second;
			}
		}
		else {
			if ((SUM_COST >= v[i].second) && (before != v[i].second)) {
				SUM_COST = v[i].second;
				before = v[i].second;
			}
		}
		SUM_KG += v[i].first;
	}

	if (SUM_KG >= M) {
		cout << SUM_COST;
	}
	else {
		cout << -1;
	}

	return 0;
}