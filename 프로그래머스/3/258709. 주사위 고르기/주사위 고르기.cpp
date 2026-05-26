#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bit>
#include <set>
#include <bitset>
using namespace std;

set<int> st;

void solve(vector<vector<int>> &dice, vector<int> &sumvector, vector<int> &dicevector, int count, int sum, int idx){
    if(idx == count){
        sumvector.push_back(sum);
    }
    else{
        for(int i = 0; i<6; i++){
            solve(dice, sumvector, dicevector, count + 1, sum + dice[dicevector[count]][i], idx);
        }
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    int n = dice.size();
    
    int fullmask = (1<<n) - 1;
    int answincnt = 0;
    
    for(int mybit = 1; mybit < (1<<n); mybit++){
        //mybit는 경우의수
        if(__popcount((unsigned int)mybit) != n / 2) continue;
        if(st.find(mybit) != st.end()) continue;
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

        solve(dice, mysum,mydice,0,0,n/2);
        solve(dice, enemysum,enemydice,0,0,n/2);
        sort(mysum.begin(), mysum.end());
        sort(enemysum.begin(), enemysum.end());
        //mysum에서 enemysum을 이길 수 있는 count 계산
        int wincnt = 0;
        for(int i : mysum){
            wincnt += lower_bound(enemysum.begin(), enemysum.end(), i) - enemysum.begin();    
        }
        
        if(wincnt > answincnt){
            answincnt = wincnt;
            answer.clear();
            
            for(int i : mydice){
                answer.push_back(i + 1);
            }
        }
        
        wincnt = 0;
        for(int i : enemysum){
            wincnt += lower_bound(mysum.begin(), mysum.end(), i) - mysum.begin();    
        }
        
        if(wincnt > answincnt){
            answincnt = wincnt;
            answer.clear();
            
            for(int i : enemydice){
                answer.push_back(i + 1);
            }
        }
        
        st.insert(mybit);
        st.insert(enemybit);
        
    }
    
    return answer;
}