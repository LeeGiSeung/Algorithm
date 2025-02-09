#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;
	//술하고 같이 초밥을 먹거나 점심 식사가 아닐 때는 초밥의 밥알을 280
	//점심 식사이면서 술과 같이 먹지 않을때는 초밥의 밥알을 320
	//술을 마시거나
	if (b == 1 || (a < 12 || a > 16)) {
		cout << 280;
	}
	else if (b == 0 && (a >= 12 || a <= 16)) {
		cout << 320;
	}

	return 0;
}