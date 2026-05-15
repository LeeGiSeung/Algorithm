#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

struct SongInfo{
    int playCount;
    int index;
    
    SongInfo(int _playCount, int _index){
        playCount = _playCount;
        index = _index;
    }
                
};

bool playSolve(pair<string,int> &a, pair<string,int> &b){
    return a.second > b.second;
}

bool songSolve(SongInfo &a, SongInfo &b){
    if(a.playCount == b.playCount){
        return a.index < b.index;
    }
    else{
        return a.playCount > b.playCount;
    }
}

map<string,int> playCount; //playcount 계산
map<string,vector<SongInfo>> songInfo; //각 노래에 대한 정보들

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    //고유번호 : genres index 번호
    
    for(int i = 0; i<genres.size(); i++){
        playCount[genres[i]] += plays[i];
        SongInfo SI(plays[i],i);
        songInfo[genres[i]].push_back(SI);
    }
    
    vector<pair<string,int>> playCountCom(playCount.begin(), playCount.end());
    vector<pair<string,vector<SongInfo>>> songInfoCom(songInfo.begin(), songInfo.end());
    
    sort(playCountCom.begin(), playCountCom.end(), playSolve);
    
    for(int i = 0; i<songInfoCom.size(); i++){
        sort(songInfoCom[i].second.begin(), songInfoCom[i].second.end(), songSolve);
    }
    
    map<string,vector<SongInfo>> sortSongInfo(songInfoCom.begin(), songInfoCom.end());
    
    for(int i = 0; i<playCountCom.size(); i++){
        vector<SongInfo> v = sortSongInfo[playCountCom[i].first];
        int count = 0;
        for(int j = 0; j<v.size(); j++){
            if(count >= 2) break;
            answer.push_back(v[j].index);
            count++;
        }
    }
    
    return answer;
}