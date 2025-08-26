#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    queue<pair<string,string>> q; //id에 해당하는 입출력 기록
    map<string, string> m; //id에 해당하는 이름
    for(int i = 0; i<record.size(); i++){
        string s = record[i];
        
        //유저 아이디와 닉네임의 길이는 1 이상 10 이하이다.
        int j = 0;
        string command = "";
        while(j<record[i].size() && record[i][j] != ' '){
            command += record[i][j];
            j++;
        }
        
        j++;
        string id = "";
        while(j<record[i].size() && record[i][j] != ' '){
            id += record[i][j];
            j++;
        }
        j++;
        q.push({id,command});
        
        if(command == "Change"){ //이건 q에 넣을 필요 없음
            string changename = "";
            while(j<record[i].size() && record[i][j] != ' '){
                changename += record[i][j];
                j++;
            }
            m[id] = changename;
            j++;
        }
        
        else if(command == "Enter"){ //이름 등록
            string name = "";
            while(j<record[i].size() && record[i][j] != ' '){
                name += record[i][j];
                j++;
            }
            j++;
            m[id] = name;
            //cout<<name<<" "<<command<<" "<<id<<endl;
        }
    }
    
    while(!q.empty()){
        string id = q.front().first;
        string command = q.front().second;
        q.pop();
        if(command == "Enter"){
            answer.push_back(m[id] + "님이 들어왔습니다.");
        }
        else if(command == "Leave"){
            answer.push_back(m[id] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}