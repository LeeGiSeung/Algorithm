#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int result = 0;
		long long a, b;
		cin >> a >> b;
		for (int i = 0; i < a; i++) {
			//우주선의 최고속도 vi(1 ≤ vi ≤ 1000)와 우주선의 연료양 fi(1 ≤ fi ≤ 1000)와 우주선의 연료소비율
			long long x, y, z;	
			cin >> x >> y >> z;
			if (x * y / z  >= b) {
				result++;
			}

		}
		cout << result << "\n";
	}


	return 0;
}