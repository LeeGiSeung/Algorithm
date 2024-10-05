#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string s;

int max_a = 1;

bool check[7][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//6과 9는 서로 바뀔수 있음

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		//9999
		int number = s[i] - '0';
		int a = 1;

		if(number == 6){
			while (true) {
				if (!check[a][6]) {
					check[a][6] = true;
					break;
				}
				else if (!check[a][9]) {
					check[a][9] = true;
					break;
				}
				a++;
			}
		}
		else if (number == 9) {
			while (true) {
				if (!check[a][6]) {
					check[a][6] = true;
					break;
				}
				else if (!check[a][9]) {
					check[a][9] = true;
					break;
				}
				a++;
			}
		}
		else {
			while (check[a][number]) {
				a++;
			}
			check[a][number] = true;
		}
		max_a = max(a, max_a);
	}

	cout << max_a;

	return 0;
}