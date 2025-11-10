#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <string.h>
using namespace std;

bool match_card(set<int> &card1, set<int> &card2, int n){
    //card덱 두개를 비교해서 n이 되는게 있으면 그 카드 두개 지움
    for(auto c : card1){
        auto it = card2.find(n - c);
        if(it != card2.end()){
            //카드가 만약 존재하면 return true
            card1.erase(c);
            card2.erase(*it);
            return true;
        }
    }
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 1;
    
    set<int> hand;
    set<int> draw;
    
    vector<int> c = cards;
    sort(c.begin(), c.end());
    int n = c[c.size() - 1];
    
    for(int i = 0; i<n/3; i++){
        hand.insert(cards[i]); //앞에 n/3 장만큼의 카드를 손에 넣음
    }
    
    for(int i = n/3; i<n; i+=2){
        //한번에 두장씩 뽑음
        
        draw.insert(cards[i]);
        draw.insert(cards[i + 1]);
        
        //draw에는 현재 선택할 카드가 아니라 일단 지나간 카드들이 모두 있는거임
        //카드 빨리 쳐낼 수 있으면 쳐내야함
        if(match_card(hand, hand, n + 1)){ //손패에 있는걸로 쳐낼 수 있으면 쳐냄
            //continue;
        }
        else if(coin >= 1 && match_card(hand, draw, n + 1)){
            coin -=1; //손패에 있는거랑 draw하나로 되는거면 cont한개 소모
        }
        else if(coin >= 2 && match_card(draw, draw, n + 1)){
            coin -=2; //draw두개로 되면 coint 2개씀
        }
        else{
            break;
        }
        
        answer++;
    }
    
    return answer;
}