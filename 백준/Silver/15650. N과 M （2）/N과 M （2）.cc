#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
#include <string>
#include <queue>

#define MAX 9

using namespace std;

int arr[MAX] = { 0, };
bool visited_NUM[MAX] = { 0, };
bool visited[MAX] = { 0, };
int n, m;

void backtracking(int num, int k) {
	if (k == m) 
	{
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++) 
	{
		if (!visited[i]) {
			visited[i] = true;
			arr[k] = i;
			backtracking(i+1, k+1);
			visited[i] = false;
		}
	}
}

int main(void) {
	
	cin >> n >>m;

	backtracking(1,0);

	return 0;
}

