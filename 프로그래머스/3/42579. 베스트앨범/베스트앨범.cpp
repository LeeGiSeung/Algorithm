#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

bool solve(const pair<string,int> &a, const pair<string,int> &b){
    return a.second > b.second;
}

bool solve2(const pair<int,int> &a, const pair<int,int> &b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,vector<pair<int,int>>> m1;
    map<string,int> m2;
    
    for(int i = 0; i<genres.size(); i++){
        m2[genres[i]] += plays[i];
        m1[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string,int>> v(m2.begin(), m2.end());
    
    sort(v.begin(), v.end(), solve);
    
    for(int i = 0; i<v.size(); i++){
        string key = v[i].first;
        int count = 0;
        sort(m1[key].begin(), m1[key].end(), solve2);
        for(int j = 0; j<m1[key].size(); j++){
            if(count >= 2){
                break;
            }
            answer.push_back(m1[key][j].first);
            count++;
        }
    }
    
    return answer;
}