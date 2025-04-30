#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string fast = " ";
    //첫 문자가 알파벳이 아닐 때에는 이어지는 알파벳은 소문자로 쓰면 됩니다.
  
    bool number = false;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == ' ') {
            fast = " ";
            answer += s[i];
            number = false;
            
        }
        else if (s[i] != ' ') {
            if ((s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') && fast == " ") { 
                //과거에 빈칸이였고 && 단어의 첫 시작이 숫자일때
                answer += s[i];
                number = true;
            }
            else if (fast == " ") {  //과거에 빈칸이였고 단어의 첫 시작이 숫자가 아닐때
                answer += toupper(s[i]); //단어의 첫 시작이 숫자가 아니라면 대문자로 넣는다.
            }
            else {
                answer += tolower(s[i]);
            }
            fast = s[i];
        }

    }

    return answer;
}