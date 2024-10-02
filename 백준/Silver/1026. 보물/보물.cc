#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, a;

vector<int> ar;
vector<int> br;

int result = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		ar.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		cin >> a;
		br.push_back(a);
	}

	sort(ar.begin(), ar.end());
	sort(br.begin(), br.end());

	for (int i = 0; i < n; i++) {
		result += ar[n-i-1] * br[i];
		//cout << ar[n - i] << " " << br[i] << endl;
		//cout << ar[n - i] * br[i] << endl;
	}

	cout << result;

	return 0;
}