#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<int>> map;
void dfs(int x, int y, int size, vector<int> &answer){
    bool zero, one;
    one = true; zero = true;
    
    for(int i = x; i< x + size; i++){
        for(int j = y; j<y + size; j++){
            if(map[i][j] == 0) one = false;
            if(map[i][j] == 1) zero = false;
        }
    }
    
    if(zero){
        answer[0]++;
        return;
    } 
    if(one){
        answer[1]++;
        return;
    } 
    
    dfs(x,y,size/2,answer);
    dfs(x,y + size / 2,size/2,answer);
    dfs(x + size / 2,y,size/2,answer);
    dfs(x + size / 2,y + size / 2,size/2,answer);
    
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    map = arr;
    //0갯수, 1갯수
    dfs(0,0,arr.size(),answer);
    return answer;
}