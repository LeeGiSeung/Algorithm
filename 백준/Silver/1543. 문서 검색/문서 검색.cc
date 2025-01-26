#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

string a, b;
int result = 0;

bool string_find(int a_index) {
	for (int i = 0; i < b.size(); i++) {
		//만약 a의 사이즈를 넘길시 return false
		if (a_index + i >= a.size()) return false;
		//만약 a의 단어와 b의 단어가 다를 경우 return false
		if (a[a_index + i] != b[i]) return false;
	}
	//위에 모두 걸리지 않았다는건 단어가 똑같다는 뜻 return true
	return true;
}

void solve() {
	//중복되는 것은 세면 안된다.
	//길이가 5인 단어인데 남은 길이가 3이면 더이상 탐색할 필요가 없다.

	//입력받은 a의 0번째 index부터 a.size index까지 탐색
	for (int i = 0; i < a.size(); i++) {
		//만약 시작점이 같을 경우
		if (a[i] == b[0]) {
			//만약 이후도 맞을 경우 정답 +1
			if (string_find(i)) {
				i += b.size() - 1;
				result++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	getline(cin, a);
	getline(cin, b);

	solve();

	cout << result;

	return 0;
}