#include <iostream>
#include <cctype>   //isupper를 쓰기위한 헤더파일
#include <string>   
 
using namespace std;
 
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);        // 입출력 시간 향상
 
    string s;
    int n;
    cin>>n;
 
    for(int i=0; i<n; i++){
 
        cin>>s;
 
        for(int i=0; i<s.length(); i++){
            if(isupper(s[i])){      //isupper : 대문자 판별
                s[i]=tolower(s[i]); //문자열에 대문자가 있으면 tolower:소문자로 바꿔라
            }
 
            //반대
            /*if(islower(s[i])){
                s[i]=toupper(s[i]);
            }*/
        }
            cout<<s<<"\n";
    }
}