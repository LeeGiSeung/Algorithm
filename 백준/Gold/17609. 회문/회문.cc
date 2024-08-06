#include <iostream>
#include <stack>

using namespace std;
int n;
string in;
int c = 3;

void pal(int s, int e, bool check) {
	while (s < e) {
		if (in[s] == in[e]) {
			s++;
			e--;
		}
		else {
			if (check == false) {
				pal(s, e - 1, true);
				pal(s + 1, e, true);
				return;
			}
			else {
				return;
			}
		}
	}
	c = check;

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in;
		c = 2;
		pal(0, in.size() - 1, false);
		cout << c << "\n";
	}
	
	return 0;
}
