#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string S, P;

int COUNT;
int P_START_INDEX;
bool CHECK_FIND = true;

bool FIND_S(int _START_INDEX, int _END_INDEX) {
	CHECK_FIND = true;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == P[_START_INDEX]) {
			for (int j = _START_INDEX; j <= _END_INDEX; j++) {
				if (S[i] != P[j]) {
					break;
				}
				else {
					if (_END_INDEX == j) {
						return true;
					}
					i++;
				}
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S;
	cin >> P;

	for (int i = 0; i < P.size(); i++) {
		COUNT++;
		P_START_INDEX = i;
		while (FIND_S(P_START_INDEX, i + 1)) {
			i++;
		}
	}

	cout << COUNT;

	return 0;
}
