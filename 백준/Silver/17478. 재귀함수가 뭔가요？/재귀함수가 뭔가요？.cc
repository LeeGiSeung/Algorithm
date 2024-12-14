#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int a;

void say(int _a) {
	for (int i = 0; i < _a; i++) {
		cout << "____";
	}
}

void jg(int _a) {
	say(_a);
	cout << "\"재귀함수가 뭔가요?\"" << "\n";
	if (_a == a) {
		say(_a);
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << "\n";
	}
	else if (_a < a) {
		say(_a);
		cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << "\n";
		say(_a);
		cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << "\n";
		say(_a);
		cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << "\n";
		jg(_a + 1);
	}
	say(_a);
	cout << "라고 답변하였지." << "\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a;
	int c = 0;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << "\n";
	jg(0);

	return 0;
}