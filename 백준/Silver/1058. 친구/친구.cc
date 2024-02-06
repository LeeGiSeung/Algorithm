#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
#define MAX_N 50

int main(void) {

	string friends_each[MAX_N];
	int two_friend_cnt[MAX_N] = { 0 };
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> friends_each[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			else if (friends_each[i][j] == 'Y') {
				two_friend_cnt[i] += 1;
			}
			else if (friends_each[i][j] == 'N') {
				for (int k = 0; k < n; k++) {
					if ((friends_each[i][k]=='Y') && (friends_each[j][k] == 'Y')) {
						two_friend_cnt[i] += 1;
						break;
					}
				}
			}
		}
	}

	int result = *max_element(two_friend_cnt, two_friend_cnt+n);
	cout << result;
		

	return 0;
	}
