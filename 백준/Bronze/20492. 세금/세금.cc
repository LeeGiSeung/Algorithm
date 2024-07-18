#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int x;
	cin >> x ;
	cout << (int)(x*0.78) << ' '<< (int)(x*(1-0.2*0.22));
	return 0;
}