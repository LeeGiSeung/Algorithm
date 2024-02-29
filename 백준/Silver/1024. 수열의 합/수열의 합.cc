#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n, l, s = -1;
	cin >> n >> l;
	vector<int> dp(101, 0);
	for (int i=2; i<=100; i++) {
		dp[i] = dp[i-1] + i-1;
	}
	while (n >= l && l <= 100) {
		int res = n/l*l+dp[l]-n;
		if (res%l==0) {
			s = (n-res)/l;
			break ;
		}
		l++;
	}
	if (n == 1 && l == 2) s = 0;// 에외 처리
	if (s<0) {
		cout << -1;
		return 0;
	}
	for (int i=0; i<l; i++) {
		cout << s+i << " ";
	}
}