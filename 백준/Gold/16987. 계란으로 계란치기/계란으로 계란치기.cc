#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int n;

int result = 0;


// _check으로 계란이 깨졌는지 안깨졌는지 확인
void solve(int _egg) {
	//만약 마지막 계란까지 모두 진행했을 경우
	if (_egg >= n) {
		int a = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].first <= 0) {
				a++;
			}
		}
		result = max(result, a);
		return;
	}
	if (v[_egg].first <= 0) solve(_egg + 1);

	else {
		bool check = false;
		for (int i = 0; i < n; i++) {
			if (_egg == i) continue;
			if (v[i].first <= 0) continue;
			v[_egg].first -= v[i].second;
			v[i].first -= v[_egg].second;
			check = true;
			solve(_egg + 1);
			v[_egg].first += v[i].second;
			v[i].first += v[_egg].second;
		}

		//다 깨져있으면 그냥 끝내야함
		if (check == false) solve(n);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	solve(0);

	cout << result;

	//1. 가장 왼쪽의 계란을 든다.
	//2. 손에 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 친다. 단 손에 든 계란이 깨졌거나 더 이상 칠 계란이 없다면 3번 진행
	//3. 오른쪽 계란을 들고 2번 과정을 반복한다. 맨 오른쪽 계란까지 진행하였으면 더 이상 진행하지 않는다.

	return 0;
}