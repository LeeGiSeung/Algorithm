#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <bit>
#include <bitset>
using namespace std;

set<int> st;

void solve(int count, int sum ,vector<int> &sumvector ,vector<int> &mydice, int t, vector<vector<int>> &dice){
    if(count == t){
        sumvector.push_back(sum);
        return;
    }
    else{
        for(int i = 0; i<6; i++){
            solve(count + 1, sum + dice[mydice[count]][i], sumvector, mydice, t, dice);
        }
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    int n = dice.size();
    int fullmask = (1<<n) - 1;
    int answerwincnt = 0;
    
    for(int mybit = 1; mybit<(1<<n); mybit++){
        if(__popcount((unsigned int)mybit) != n/2) continue;
        if(st.find(mybit) != st.end()) continue; //이미 발견한거면 안됨
        
        int enemybit = mybit ^ fullmask;
        
        vector<int> mydice;
        vector<int> enemydice;
        
        for(int i = 0; i<n; i++){
            if(mybit & (1<<i)){
                mydice.push_back(i);
            }
            else{
                enemydice.push_back(i);
            }
        }
        
        vector<int> mysum;
        vector<int> enemysum;
        
        solve(0,0,mysum,mydice, n / 2, dice);
        solve(0,0,enemysum,enemydice, n / 2, dice);
        
        sort(enemysum.begin(), enemysum.end());
        sort(mysum.begin(), mysum.end());
        int wincnt = 0;
        for(int i = 0; i<mysum.size(); i++){
            wincnt  += lower_bound(enemysum.begin(), enemysum.end(), mysum[i]) - enemysum.begin();
        }
        
        if(wincnt > answerwincnt){
            answerwincnt = wincnt;
            answer.clear();

            for(int j = 0; j<mydice.size(); j++){
                answer.push_back(mydice[j] + 1);
            }
        }
        
        wincnt = 0;
        
        for(int i = 0; i<enemysum.size(); i++){
            wincnt += lower_bound(mysum.begin(), mysum.end(), enemysum[i]) - mysum.begin();
        }
        
        if(wincnt > answerwincnt){
            answerwincnt = wincnt;
            answer.clear();

            for(int j = 0; j<enemydice.size(); j++){
                answer.push_back(enemydice[j] + 1);
            }
        }
        
        st.insert(mybit);
        st.insert(enemybit);
        
    }
    
    return answer;
}