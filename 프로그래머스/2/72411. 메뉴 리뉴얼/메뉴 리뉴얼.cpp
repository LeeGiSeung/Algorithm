#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

bool st(pair<string,int> &a, pair<string,int> &b){
    return a.second > b.second;
}

void dfs(map<string, int> &m, string& order, string &s, int index, int depth){
    //index 순열 index
    //depth 길이
    if(depth == s.size()){
        m[s]++;
        return;
    }
    else{
        for(int i = index; i<order.size(); i++){
            s[depth] = order[i];
            dfs(m, order, s, i + 1, depth + 1);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> m;
    for(int i = 0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end()); //일단 정렬
        for(int j = 0; j<course.size(); j++){
            string tmp = "";
            tmp.resize(course[j]);
            dfs(m,orders[i],tmp,0,0);
        }
    }
    //가능한 모든 경우의 수 됨
    
    vector<pair<string,int>> lst;
    
    for(pair<string,int> i : m){
        if(i.second > 1){ //2번 이상 나온 메뉴일 경우 리스트에 일단 추가함
            lst.push_back(i);
        }
    }
    
    sort(lst.begin(), lst.end(), st);
    //2번 이상 나온 코스메뉴 구성 정렬
    cout<<lst.size()<<endl;
    for(int i = 0; i<course.size(); i++){
        int max = 0;
        
        for(int j = 0; j<lst.size(); j++){
            if(lst[j].first.size() != course[i]) continue;
            
            if(max == 0){
                answer.push_back(lst[j].first);
                max = lst[j].second;
            }
            else if(max == lst[j].second){
                answer.push_back(lst[j].first);
            }
            else break;
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}