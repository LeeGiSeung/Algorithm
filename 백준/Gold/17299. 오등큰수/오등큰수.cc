#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define MAX 1000000

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> arr(n + 1);
	vector<int> ngf(n + 1, -1);
	vector<int> cnt(MAX + 1, 0);
	stack<int> st;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	for (int i = 1; i <= n; i++)
	{
		while (!st.empty() && cnt[arr[st.top()]] < cnt[arr[i]])
		{
			ngf[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << ngf[i] << ' ';
	}
	cout << '\n';

	return 0;
}