#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;
int n;
vector<int> v;

int good = 0;

//두개의 합
//1
//2
//3 2, 1
//4 3, 1
//5 3, 2
//6 4, 2
//7 4, 3
//8 5, 3
//9 5, 4
//10 7, 3

//완전 탐색하면 뻑날거고 투포인터?

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if (n < 3) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {

		int s = 0;
		int e = n-1;

		while (s < e){
			if (v[s] + v[e] < v[i]) {
				s++;
			}
			else if (v[s] + v[e] > v[i]) {
				e--;
			}
			else {
				if (s == i) s++;
				else if (e == i) e--;
				else if(v[s] + v[e] == v[i]) {
					good++;
					break;
				}
			}
		}
	}
	
	cout << good;

	return 0;
}
