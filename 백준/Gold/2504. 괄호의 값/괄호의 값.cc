#include<iostream> 
#include<stack>
#include<string.h>

using namespace std;
int main()
{
	stack<char> s;
	string str;
	int answer = 0, temp = 1;
	cin >> str;
    
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') //일단 시작괄호는 무조건 2를 곱함
		{
			temp *= 2;
			s.push('(');
		}
		else if (str[i] == '[') //일단 시작괄호는 무조건 3을 곱함
		{
			temp *= 3;
			s.push('[');
		}
		else if (str[i] == ')')
		{
			//잘못된 괄호 맺음인 경우
			if (s.empty() || s.top() != '(')
			{
				answer = 0;
				break;
			}
			if (str[i - 1] == '(')
			{
				answer += temp;
			}
			temp /= 2;
			s.pop();
		}
		else if (str[i] == ']')
		{
			if (s.empty() || s.top() != '[')
			{
				//잘못된 괄호 맺음인 경우
				answer = 0;
				break;
			}
			if (str[i - 1] == '[')
			{
				answer += temp;
			}
			temp /= 3;
			s.pop();
		}
	}
	if (!s.empty())
	{
		answer = 0;
	}
	std::cout << answer;
}
