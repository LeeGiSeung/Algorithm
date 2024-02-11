#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#define MAX 9

using namespace std;
int n, m;
int number[MAX] = { 0, };
bool visited[MAX] = {0,};


void back(int num,int cnt) {
	if (m == cnt) {
		for (int i = 0; i < m; i++) {
			cout << number[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = num; i <= n; i++) 
	{
		number[cnt] = i;
		back(i, cnt + 1);
	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	back(1, 0);

	return 0;
}