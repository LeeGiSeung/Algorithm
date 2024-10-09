#include <iostream>
#include <vector>
using namespace std;

int v[26];
vector<char> result;
int odd = 0;
int odd_idx = 40;

char abc[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

string s;
//알파벳 대문자로만 된 최대 50글자이다.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	int k = s.size();

	for (int i = 0; i < s.size(); i++) {
		char a = s[i] - 'A';
		v[a]++;
	}

	for (int i = 0; i < 26; i++) {
		if (v[i] % 2 == 1) {
			odd++;
			odd_idx = i;
		}
	}

	if (odd > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	//A 3
	//B 2
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < v[i] / 2; j++) {	
			result.push_back(abc[i]);
		}
	}

	if (odd_idx != 40) {
		result.push_back(abc[odd_idx]);
	}

	for (int i = 25; i >= 0; i--) {
		for (int j = 0; j < v[i] / 2; j++) {
			result.push_back(abc[i]);
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}

	return 0;
}