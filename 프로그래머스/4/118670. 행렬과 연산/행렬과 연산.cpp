#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer(rc.size(), vector<int>(rc[0].size(), 0));
    
    deque<int> left;
    deque<int> right;
    deque<deque<int>> middle;
    
    int n = rc.size() - 1;
    int m = rc[0].size() - 1;
    
    for(int i = 0; i<rc.size(); i++){
        left.push_back(rc[i][0]);
        right.push_back(rc[i][m]);
        deque<int> d;
        for(int j = 1; j<m; j++){
            d.push_back(rc[i][j]);
        }
        middle.push_back(d);
    }
    
    for(string s : operations){
        if(s == "Rotate"){
            middle[0].push_front(move(left.front()));
            left.pop_front();
            
            right.push_front(move(middle[0].back()));
            middle[0].pop_back();
            
            middle[n].push_back(move(right.back()));
            right.pop_back();
            
            left.push_back(move(middle[n].front()));
            middle[n].pop_front();
        }
        else{
            left.push_front(move(left.back()));
            left.pop_back();
            
            right.push_front(move(right.back()));
            right.pop_back();
            
            middle.push_front(move(middle.back()));
            middle.pop_back();
        }
    }
    
    for(int i = 0; i<rc.size(); i++){
        answer[i][0] = left[i];
        answer[i][m] = right[i];
        int col = 1;
        for(int x : middle[i]){
            answer[i][col++] = x;
        }
    }
    
    return answer;
}