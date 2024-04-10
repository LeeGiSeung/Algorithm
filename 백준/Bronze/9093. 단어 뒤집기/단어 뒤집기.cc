#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();		//입력 버퍼 지워주기(cin 사용 후 \n가 입력버퍼에 남아있어서 getline에서 입력 처리가 된다.)
	while (n--)
	{
		string arr;
		getline(cin, arr);		//띄어쓰기 포함한 문자열 입력
		arr += ' ';				//문장의 끝도 변화시키기 위함
		stack<char> s;

		for (char ch : arr)		//배열 arr의 값을 순차적으로 ch에 저장
		{
			if (ch == ' ')			//문장의 중간 혹은 끝
			{
				while (!s.empty())	//스택이 비워질 때까지
				{
					cout << s.top();//문자 출력
					s.pop();
				}
				cout << ch;		//띄어쓰기 출력
			}
			else				//띄어쓰기가 입력이 안될 때
				s.push(ch);
		}
	}
	return 0;
}