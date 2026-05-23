#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

vector<int> bitcheck;

bool check(int b){
    for(int i = 0; i<bitcheck.size(); i++){
        if((bitcheck[i] & b) == bitcheck[i]) return true;
    }
    return false;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    int rowsize = relation.size();
    int colsize = relation[0].size();
    
    for(int i = 1; i<(1<<colsize); i++){
        
        if(check(i)) continue;
        
        set<string> s;
        
        for(int row = 0; row<rowsize; row++){
            
            string str = "";
            for(int col = 0; col<colsize; col++){
                
                if(i & (1<<col)){
                    str += relation[row][col] + "/";
                }
                
            }
            s.insert(str);
        }
        
        if(s.size() == rowsize){
            bitcheck.push_back(i);
        }
    }
    
    answer = bitcheck.size();
    
    return answer;
}