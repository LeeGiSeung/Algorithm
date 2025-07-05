#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
set<string> s;
vector<string> user;
vector<string> ban;
bool check[10];

int check_ban(string user, string ban){
    if(user.size() != ban.size()){
        return 0;
    }
    
    for(int i = 0; i<ban.size(); i++){
        
        if(ban[i] == '*') continue;
        if(user[i] != ban[i]) return 0;
        
    }
    return 1;
}

void dfs(int idx){
    if(idx == ban.size()){
        string str = "";
        
        for(int i = 0; i<user.size(); i++){
            if(check[i]) str += i + '0';
        }
        
        s.insert(str);
        
    }
    else
    {
        for(int i = 0; i<user.size(); i++){
            if(check[i]) continue;

            if(check_ban(user[i], ban[idx])){
                check[i] = true;
                dfs(idx + 1);
                check[i] = false;
            }
        }
    }

}

int solution(vector<string> user_id, vector<string> banned_id) {
    user = user_id;
    ban = banned_id;
    dfs(0);
    
    return s.size();
}