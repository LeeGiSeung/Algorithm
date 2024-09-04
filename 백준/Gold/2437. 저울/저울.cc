#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n; // 1<=N<=1000 
int sum;

int main()
{
	cin >> n;
	
	for (int i = 0 ; i < n ; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.begin(), v.end());
	
	for (int i = 0 ; i < n ; ++i)
	{
		if (v[i] > sum + 1)
			break;
		sum += v[i];
	}
	
	cout << sum + 1;
	
	
	return 0;
}
