#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool match(string user, string ban){
    if(user.size() != ban.size()) return false;
    
    for(int i = 0; i<user.size(); i++){
        if(ban[i] == '*') continue;
        if(user[i] != ban[i]) return false;
    }
    
    return true;
}

set<set<string>> answers;
void dfs(int idx, vector<bool> &check, set<string> &s, vector<string> user_id, vector<string> banned_id){
    if(idx == banned_id.size()){
        answers.insert(s);
        return;
    }
    
    for(int i = 0; i<user_id.size(); i++){
        if(check[i]) continue;
        if(match(user_id[i], banned_id[idx])){
            check[i] = true;
            s.insert(user_id[i]);
            
            dfs(idx + 1, check, s, user_id, banned_id);
            
            check[i] = false;
            s.erase(user_id[i]);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vector<bool> check(user_id.size(), false);
    set<string> s;
    
    int idx = 0;
    
    dfs(idx, check, s, user_id, banned_id);
    answer = answers.size();
    return answer;
}