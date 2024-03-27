#include<iostream>
#include<string.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string a; // 전체 문자열 변수
    string b; // 폭발 문자열 변수
    string t = ""; // 임시 문자열 
    cin >> a >> b;
    int a_len = a.length(); // 전체 문자열 길이
    int b_len = b.length(); // 폭발 문자열 길이
    for (int i = 0; i < a.length(); i++)
    {
        t += a[i]; // 문자 추가
        if(t.length()>=b_len){ // 임시 문자 길이가 폭발 문자열 보다 크거나 같을 때
            bool flag = true; // 폭발 문자열 있는지 확인하는 flag
            for (int j = 0; j < b_len; j++){ 
                if(t[t.length()-b_len+j] != b[j]){
                    flag = false;
                    break;
                } // t뒤에서 폭발 문자열 길이만큼 비교
            }
 
            if(flag) // 폭발 문자열일 경우 삭제 
                t.erase(t.end() - b_len, t.end());
        }
    }
        if (t.empty()) // 남아 있는 문자열이 없는 경우
            cout << "FRULA" << '\n';
        else
            cout << t << '\n';
    return 0;
}
