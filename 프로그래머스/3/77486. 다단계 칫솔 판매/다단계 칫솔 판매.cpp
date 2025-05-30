#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    map<string ,int> m;
    map<string ,string> link;
    
    for(int i = 0; i<enroll.size(); i++){
        m.insert({enroll[i], 0});
        link.insert({enroll[i], referral[i]});
    }
    
    //referral[i] 번째가 enroll[i] 번째를 참여시킴
    
    queue<pair<string ,int>> q;
    for(int i = 0; i<seller.size(); i++){
        int cur = amount[i] * 100;
        q.push({seller[i], cur});
        
    }
    
    while(!q.empty()){
        string name = q.front().first;
        int toss = q.front().second;
        q.pop();
        
        string next_name = link[name]; //다음 이름
        
        int next_toss = toss / 10; //다음에 넘겨줄 것
        
        m[name] += toss - next_toss; //받은 것에서 10%주고 나머진 내가 가짐
        
        if(next_name != "-" && next_toss != 0){
            
            q.push({next_name, next_toss});
    
        } 
    }
    
    for(int i = 0; i<enroll.size(); i++){
        answer.push_back(m[enroll[i]]);
    }
    
    //칫솔 한 개를 판매하여 얻어지는 이익은 100 원으로 정해져 있습니다
    
    return answer;
}