#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int n , k;
int man[7];
int woman[7];
int result = 0;
int main()	
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < 7; i++) {
		man[i] = 0;
		woman[i] = 0;
	}

	while (n--) {
		int s, y;
		cin >> s >> y;
		//여학생
		if (s == 0) {
			woman[y] += 1;
		}
		//남학생
		else if (s == 1) {
			man[y] += 1;
		}
	}

	for (int i = 1; i < 7; i++) {
		if (man[i] % k > 0) {
			result += man[i] / k + 1;
		}
		else {
			result += man[i] / k;
		}
		if (woman[i] % k > 0) {
			result += woman[i] / k + 1;
		}
		else {
			result += woman[i] / k;
		}
	}

	cout << result;

	return 0;
}