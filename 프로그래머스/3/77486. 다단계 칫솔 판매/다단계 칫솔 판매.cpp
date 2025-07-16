#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
vector<int> answer;
map<string,int> cost;
map<string,string> node;

vector<string> _enroll;
vector<string> _referral;
vector<string> _seller;
vector<int> _amount;

void find_answer(string s, int money){
    if(money<1) return;
    //money는 현재 사람에게 들어오는 돈
    int cas = money / 10;
    cost[s] += money - cas;
    find_answer(node[s], cas);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    _enroll = enroll;
    _referral = referral;
    _seller = seller;
    _amount = amount;
    
    for(int i = 0; i<enroll.size(); i++){
        if(referral[i] == "-") continue;
        else{
            node[enroll[i]] = referral[i];
        }
    }
    
    for(int i = 0; i<seller.size(); i++){
        //1200원을 벌면 1080원을 가지고 120원을 보냄
        int money = amount[i] * 100;
        find_answer(seller[i], money); //자신의 부모 에게 보냄
    }
    
    for(int i = 0; i<enroll.size(); i++){
        answer.push_back(cost[enroll[i]]);
    }
        
    return answer;
}