#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n, s, r;
vector<int> false_kayak;
int kayak[11];

int result = 0;

//배가 부서지지 않은 경우 ,배가 부서진 경우, 배를 추가로 가져온 경우

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s >> r;
	for (int i = 0; i < s; i++) {
		int a;
		cin >> a;
		kayak[a] = 1;
		false_kayak.push_back(a);
	}

	for (int i = 0; i < r; i++) {
		int a;
		cin >> a;
		if (kayak[a] == 1) {
			kayak[a] = 0;
		}
		else {
			kayak[a] = 2;
		}
	}

	sort(false_kayak.begin(), false_kayak.end());

	for (int i = 0; i < s; i++) {

		bool flag = false;

		//여분의 배를 챙겨온 경우
		if (kayak[false_kayak[i]] == 0) continue;


		//양쪽 배를 확인해야 하기 때문에 좌측 먼저 물어봐야함
		if (kayak[false_kayak[i] - 1] == 2) {
			kayak[false_kayak[i] - 1] = 0;
			kayak[false_kayak[i]] = 0;
			flag = true;
		}
		else if (kayak[false_kayak[i] + 1] == 2) {
			kayak[false_kayak[i] + 1] = 0;
			kayak[false_kayak[i]] = 0;
			flag = true;
		}

		if (!flag) result++;

	}

	cout << result;

	return 0;
}