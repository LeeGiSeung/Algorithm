#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> sv1;
    vector<string> sv2;
    //입력으로 들어온 문자열은 두 글자씩 끊어서 다중집합의 원소로 만든다.
    //기타 공백이나 숫자, 특수 문자가 들어있는 경우는 그 글자 쌍을 버린다.
    
    for(int i = 0; i<str1.size() - 1; i++){
        string s = "";
        char s1 = toupper(str1[i]);
        char s2 = toupper(str1[i + 1]);
        if(s1 >= 'A' && s1 <= 'Z' && s2 >= 'A' && s2 <= 'Z'){
            s.push_back(s1);
            s.push_back(s2);
            sv1.push_back(s);
        }
    }
    for(int i = 0; i<str2.size() - 1; i++){
        string s = "";
        char s1 = toupper(toupper(str2[i]));
        char s2 = toupper(toupper(str2[i + 1]));
        if(s1 >= 'A' && s1 <= 'Z' && s2 >= 'A' && s2 <= 'Z'){
            s.push_back(s1);
            s.push_back(s2);
            sv2.push_back(s);
        }
    }
    if(sv1.size() == 0 && sv2.size() == 0) return 65536;
    int ct = 0;
    for(auto s : sv1){
        auto index = find(sv2.begin(), sv2.end(), s);
        if(index != sv2.end()){
            sv2.erase(index);
            ct++;
        }
    }
    
    float ans = (float)ct / (sv1.size() + sv2.size());
    
    answer = ans * 65536; 
    
    return answer;
}