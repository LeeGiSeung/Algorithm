#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int limit = 0;
    map<string, int> s;
    map<string, int> cur;
    vector<pair<int,int>> v;
    for(int i = 0; i<gems.size(); i++){
        s[gems[i]]++;
    }
    
    limit = s.size(); //보석이 limit개 만큼 있으면 됨
    
    int left = 0;
    int right = 0;
    
    while(right < gems.size()){
        cur[gems[right]]++; //개추 추가
        right++;
        bool check = false;
        if(cur.size() == limit){ //개수가 똑같아지면 왼쪽을 줄여서 최소
            check = true;
            while(cur[gems[left]] > 1){
                cur[gems[left]]--;
                left++;
            }
        }
        
        if(check){
            //cout<<left<<" "<<right<<endl;
            v.push_back({left,right});
        }
    }
    
    left = 0;
    right = 0;
    int rind = 1e8;
    
    for(int i = 0; i<v.size(); i++){
        if(v[i].second - v[i].first < rind){
            left = v[i].first;
            right = v[i].second;
            rind = right - left;
        }
    }
    
    answer.push_back(left + 1);
    answer.push_back(right);
    
    return answer;
}