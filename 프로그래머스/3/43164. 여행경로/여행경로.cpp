#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool check[10001];
vector<string> answer;
bool solve(const vector<string> &a, const vector<string> &b){
    if(a[0] != b[0]) return a[0] < b[0];
    else if(a[0] == b[0]){
        return a[1] < b[1];
    }
}

void dfs(string s, vector<vector<string>> tickets, vector<string> c, bool &currect){
    string cur = s;
    
    if(currect) return;
    
    c.push_back(s);
    
    if(tickets.size() + 1 == c.size()){
        answer = c;
        currect = true;
    }
    
    for(int i = 0; i<tickets.size(); i++){
        if(check[i]) continue;
        if(s == tickets[i][0]){
            check[i] = true;
            dfs(tickets[i][1],tickets, c, currect);
            check[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    //항상 "ICN" 공항에서 출발
    
    sort(tickets.begin(), tickets.end(), solve);
    vector<string> c;
    bool currect = false;
    
    dfs("ICN",tickets,c, currect);
    
    return answer;
}