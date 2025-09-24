#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solve(vector<bool> &check, vector<int> &cards, int index){
    int count = 0;
    //index boxindex 
    while(!check[index]){
        check[index] = true;
        int next = cards[index] - 1;
        count++;
        index = next;
    }

    return count;
}

int solution(vector<int> cards) {
    int answer = 1;
    
    //상자 안에 들어있는 카드 번호가 순서대로 담긴 배열 cards가 매개변수로 주어질 때,
    
    //1 2 3 4 5 6 7 8
    //8,6,3,7,2,5,1,4
    
    //4 7 1 8
    vector<int> v;
    vector<bool> check(cards.size() + 1, false);
    for(int i = 0; i<cards.size(); i++){
        if(check[i]) continue;
        int count = solve(check, cards, i);
        v.push_back(count);
    }
    
    if(v.size() < 2) return 0;
    sort(v.begin(), v.end());
    
    answer = v[v.size() - 1] * v[v.size() - 2];
    
    return answer;
}