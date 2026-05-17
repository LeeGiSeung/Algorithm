#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int answer;

void solve(int energy, vector<vector<int>> &dungeons, vector<bool> &check, int locanswer){
    
    answer = max(locanswer, answer);
    
    for(int i = 0; i<dungeons.size(); i++){
        if(check[i]) continue;
        if(dungeons[i][0] > energy) continue; //필요 피로도가 높으면 안됨
        check[i] = true;
        solve(energy - dungeons[i][1], dungeons, check, locanswer+1);
        check[i] = false;
        
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    answer = 0;
    
    //필요 피로도 : 던전을 탐험하기 위해 가지고 있어야함
    //소모 피로도 : 던전을 탐험한 후 소모됨
    
    //유저가 탐험할 수 있는 최대 던전 수
    
    //소모필요도가 가장 적은 던전부터 들어갈 수 있는 던전 한으로 다녀오면됨
    
    vector<bool> check(dungeons.size(), false);
    
    solve(k ,dungeons, check, answer);
    
    return answer;
}