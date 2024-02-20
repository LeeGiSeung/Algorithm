#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int n;
//이렇게 빈공간을 할애할시 문제의 4MB 용량을 뛰어넘게됨
int mx[3] = { 0 };
int mi[3] = { 0 };
int x, y, z;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> x >> y >> z;

	mx[0] = x;
	mx[1] = y;
	mx[2] = z;

	mi[0] = x;
	mi[1] = y;
	mi[2] = z;

	for (int i = 1; i < n; i++) {
		int q, w, e;
		x, y, z = 0;
		cin >> x >> y >> z;

		q = mx[0];
		w = mx[1];
		e = mx[2];

		mx[0] = max(q, w) + x;
		mx[1] = max(q, max(w,e)) + y;
		mx[2] = max(w, e) + z;

		q = mi[0];
		w = mi[1];
		e = mi[2];

		mi[0] = min(q, w) + x;
		mi[1] = min(q, min(w, e)) + y;
		mi[2] = min(w, e) + z;
		
	}

	cout << max(mx[0], max(mx[1], mx[2])) << " " << min(mi[0], min(mi[1], mi[2]));

	return 0;

}