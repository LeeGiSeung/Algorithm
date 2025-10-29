#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    map<string, string> m;
    map<string, int> price;
    
    for(int i = 0; i<referral.size(); i++){
        m[enroll[i]] = referral[i];
    }
    /*
    map<string, string> m;
    map<string, int> price;
    */
    
    for(int i = 0; i<seller.size(); i++){
        string cur = seller[i];
        int amo = amount[i] * 100; 
        
        while(cur != "-"){ //최상위 아닐때
            if(amo <= 0) break;
            int next = amo / 10; 
            price[cur] += amo - next; //현재 값에서 10% 뺀거
            amo = next; //다음으로 보낼꺼 10%만
            
            cur = m[cur]; //자신을 자식으로 생각하는 부모로 감
        }
        
        price[cur] += amo; //minho 한테 마지막 값 더함
    }
    
    for(int i = 0; i<enroll.size(); i++){
        answer.push_back(price[enroll[i]]);
    }
    //시간초과?
    return answer;
}