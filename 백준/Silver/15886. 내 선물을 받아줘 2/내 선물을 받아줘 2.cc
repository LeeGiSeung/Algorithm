#include <iostream>
#include <deque>

using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; scanf("%d", &n);
	char str[1010]; scanf("%s", str);
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (str[i] == 'E' && str[i + 1] == 'W') ans++;
	}
	printf("%d", ans);

	
	return 0;
}