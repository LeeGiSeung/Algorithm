#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int percent[4] = {40,30,20,10};

void dfs(vector<vector<int>>& users, vector<int> &emoticons, vector<int> &per, vector<int> &answer){
    if(per.size() == emoticons.size()){
        //할 수 있는 경우의 수일경우
        int allpay = 0; //현재 할인율로 벌어들인 수익
        int count = 0;
        for(int i = 0; i<users.size(); i++){
            int sum = 0; //현재 유저의 지불한 돈
            for(int j = 0; j<per.size(); j++){
                if(users[i][0] <= per[j]){
                    sum += emoticons[j] * (100 - per[j]) / 100;
                }
            }
            
            if(sum >= users[i][1]){
                count++;
            }
            else{
                allpay += sum;
            }
        }
        //count 현재 할인율로 플러스 가입 수
        //allpay 현재 할인율로 번 돈
        
        if(count > answer[0]){ //가입자 수가 더 많으면 늘어남
            answer[0] = count;
            answer[1] = allpay;
        }
        else if(allpay > answer[1] && count >= answer[0]){
            answer[0] = count;
            answer[1] = allpay;
        }
        
        return;
    }
    else{
        for(int i = 0; i<4; i++){
            per.push_back(percent[i]);
            dfs(users, emoticons, per, answer);
            per.pop_back();
        }
    }
    return;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2);
    vector<int> per;
    
    dfs(users, emoticons, per, answer);
    
    return answer;
}