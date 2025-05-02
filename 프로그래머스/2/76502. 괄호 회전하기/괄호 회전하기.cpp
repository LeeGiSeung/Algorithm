#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); i++) { //문자열 s만큼 반복


        stack<char> st;
        bool match = true;
        for (int j = 0; j < s.size(); j++) { //문자열 회전
            int index = (j + i) % s.size();

            if (st.empty()) { //비어있으면 그냥 넣음
                st.push(s[index]);
                if (s[index] == ']' || s[index] == '}' || s[index] == ')') {
                    match = false;
                    break;
                }
            }
            else if (s[index] == '[' || s[index] == '{' || s[index] == '(') { //열린건 그냥 넣음
                st.push(s[index]);
            }

            else if ((st.top() == '[' && s[index] == ']') || (st.top() == '(' && s[index] == ')') || (st.top() == '{' && s[index] == '}')) { //꼭대기랑 자기랑 같으면
                st.pop();
            }
            else {
                match = false;
                break;
            }
        }

        if (st.empty() && match) {
            answer++;
        }
    }

    return answer;
}

int main() {
    solution("(");
}