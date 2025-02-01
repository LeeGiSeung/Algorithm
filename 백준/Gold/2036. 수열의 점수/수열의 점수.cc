	#include <iostream>
	#include <cstring>
	#include <algorithm>
	#include <vector>
	#include <queue>
	#include <string>
	#include <cmath>
	using namespace std;

	int n;

	vector<long long> pl;
	vector<long long> mi;
	long long result = 0;


	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		cin >> n;

		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			if (a <= 0) {
				mi.push_back(a);
			}
			else {
				pl.push_back(a);
			}
		}
		//2개씩 짝으로 하고 제일 작은건 그냥 더해줘야함
		sort(pl.begin(), pl.end(), greater<long long>());
		sort(mi.begin(), mi.end());

		if (pl.size() > 0) {
			for (int i = 0; i < pl.size(); i += 2) {
				if (i == pl.size() - 1) result += pl[i];
				else if (pl[i] + pl[i + 1] > pl[i] * pl[i + 1]) {
					result += (pl[i] + pl[i + 1]);
				}
				else {
					result += (pl[i] * pl[i + 1]);
				}
			}
		}


		if (mi.size() > 0) {
			for (int i = 0; i < mi.size(); i += 2) {
				if (i == mi.size() - 1) result += mi[i];
				else {
					result += mi[i] * mi[i + 1];
				}
			}
		}

		cout << result;

		return 0;
	}