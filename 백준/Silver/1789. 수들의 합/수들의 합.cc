#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; 

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	long long result = 0; 
	cin >> result; 

	int cnt = 0; 
	int x = 1; 
	long long sum = 0; 
	while (1) {
		sum += x; 
		cnt++;
		if (result <sum) {
			cout << cnt-1; 
			break; 
		}
		x++;

	}


}