#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

bool ispri(int bit, vector<int> &ans){
    for(int check : ans){
        //0010 1110 
        if((check & bit) == check) return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    int row = relation.size();
    int cor = relation[0].size();
    int all = 1<<cor;
    vector<int> ans;
    
    for(int bit = 1; bit<all; bit++){ //1~16(15)까지의 경우의 수
        set<string> s;
        for(int i = 0; i<row; i++){
            string cur = "";
            for(int j = 0; j<cor; j++){
                if(bit & 1<<j) cur += relation[i][j];
            }
            s.insert(cur);
        }
        if(s.size() == row && ispri(bit,ans)) ans.push_back(bit);
    }
    
    return ans.size();
}