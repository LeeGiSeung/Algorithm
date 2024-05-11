#include<iostream>
#include<algorithm>
using namespace std;
 
int main() {
	string S; // 단어 S
	cin >> S; 
 
	int alp[26] = { 0, }; // 알파벳 개수 담는 배열
 
	for (int i = 0; i < S.length(); i++)
	{
		alp[S[i] - 'a'] +=1;
	}
 
	for (int i = 0; i < 26; i++)
	{
		cout << alp[i] << ' ';
	}
	
	return 0;
}