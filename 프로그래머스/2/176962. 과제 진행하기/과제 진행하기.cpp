#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

struct Data{
    string name;
    int starttime;
    int playtime;
};

bool st(Data &a, Data &b){
    if(a.starttime != b.starttime){
        return a.starttime < b.starttime;
    }
    return a.playtime > b.playtime;
}

int int_to_time(string s){
    int time = 0;
    
    time += stoi(s.substr(0,2)) * 60 + stoi(s.substr(3,2));
    
    return time;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string,int>> s; //과제 이름, 남은 시간
   
    //과제를 끝낸 순서대로 이름
    vector<Data> data;
    for(int i = 0; i<plans.size(); i++){
        Data v;
        v.name = plans[i][0];
        v.starttime = int_to_time(plans[i][1]);
        v.playtime = stoi(plans[i][2]);
        data.push_back(v);
    }
    
    //starttime 순서대로 정렬
    sort(data.begin(), data.end(), st);
    
    int time = 0;
    
    for(int i = 0; i<data.size(); i++){
        int curtime = data[i].starttime;
        
        while(curtime > time){
            if(!s.empty()){
                s.top().second--;
                if(s.top().second == 0){
                    answer.push_back(s.top().first);
                    s.pop();
                }
            }
            time++;
        }
        
        s.push({data[i].name, data[i].playtime});
    }

    while(!s.empty()){
        answer.push_back(s.top().first);
        s.pop();
    }

    
    return answer;
}