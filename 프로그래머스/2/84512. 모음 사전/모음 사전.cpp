#include <string>
#include <vector>
#include <iostream>
using namespace std;
int cnt = -1;
int answer = 0;
string answord;
string AEIOU = "AEIOU";
void dfs(string cur, bool &ch){
    if(ch) return;
    
    cnt++;
    cout<<cur<<endl;
    if(cur == answord){
        ch = true;
        answer = cnt;
        return;
    }
    
    if(cur.size() > 4) return;
    
    for(int i = 0; i<5; i++){
        dfs(cur + AEIOU[i], ch);
    }
    return;
}

int solution(string word) {   
    answord = word;
    string s = "";
    bool ch = false;
    dfs(s, ch);
    
    return answer;
}