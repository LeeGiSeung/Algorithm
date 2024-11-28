#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;
int check[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> v;
		vector<int> PLAYER;
		long long RESULT = 0;
		int HIGH_COST = 0;
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			HIGH_COST = max(HIGH_COST, b);
			check[b] += 1;
			v.push_back(b);
		}

		for (int j = 0; j < v.size(); j++) {
			//주식 판매
			if (v[j] == HIGH_COST) {
				for (int z = 0; z < PLAYER.size(); z++) {
					RESULT += (HIGH_COST - PLAYER[z]);
				}
				PLAYER.clear();
				check[HIGH_COST] -= 1;
				while (check[HIGH_COST] == 0 && HIGH_COST > 0) {
					HIGH_COST--;
				}
			}
			//주식 구매
			else {
				check[v[j]] -= 1;
				PLAYER.push_back(v[j]);
			}
			//아무것도 안한다.
		}
		cout << RESULT << "\n";
	}


	return 0;
}