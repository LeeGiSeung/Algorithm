#include <iostream>
#include <vector>
#include <cstring>

char v[20];


int cur = 0;
using namespace std;
int result = -999999999;

string s;
int n;

void dfs(int cur , int tmp) {

	//연산 범위가 n을 넘고 연산한 결과인 tmp가 result를 넘었을 경우 return
	if (cur > n && tmp > result) {
		result = tmp;
		return;
	}

	//괄호 연산 할 수 있음
	if (cur + 2 < n) {
		//현재 숫자 위치 기준으로 앞의 숫자와 연산을 한 다음에 이전 값을 더한 다음에 다음 연산에 더해줘야함. 그런데 현재 위치가 0이라면 이전 값이 없기 때문에 바로 넣어준다.
		//char 형태이기 때문에 int 형변환을 위해 - '0'
		int cur1 = (s[cur] - '0');
		int cur2 = (s[cur + 2] - '0');
		int cur_tmp = 0;
		if (s[cur + 1] == '+') {
			cur_tmp = cur1 + cur2;
		}
		else if (s[cur + 1] == '-') {
			cur_tmp = cur1 - cur2;
		}
		else if (s[cur + 1] == '*') {
			cur_tmp = cur1 * cur2;
		}
		//또 괄호 연산이 가능하다고 가정으로 넘기는 것임
		if (cur == 0) {
			dfs(cur + 4, cur_tmp);
		}
		else {
			if (s[cur - 1] == '+') {
				cur_tmp = cur_tmp + tmp;
			}
			else if (s[cur - 1] == '-') {
				cur_tmp = tmp - cur_tmp;
			}
			else if (s[cur - 1] == '*') {
				cur_tmp = cur_tmp * tmp;
			}
			dfs(cur + 4, cur_tmp);
		}
	}
	//괄호 연산을 하지 않는 경우
	if (cur == 0) {
		dfs(cur + 2, s[cur] - '0');
	}
	else {
		if (s[cur - 1] == '+') {
			dfs(cur + 2, (s[cur] - '0') + tmp);
		}
		else if (s[cur - 1] == '-') {
			dfs(cur + 2, tmp - (s[cur] - '0'));
		}
		else if(s[cur - 1] == '*') {
			dfs(cur + 2, (s[cur] - '0') * tmp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> s;

	dfs(0, 0);

	cout << result;

	return 0;
}