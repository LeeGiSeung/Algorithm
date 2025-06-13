#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int playtime;
int advtime;

int ct = 0;
int gotime = 100000000;
int answertime = 0;
int maxtime = 0;

string SetTime(int answertime){
    string answer = "";
    if(answertime / 3600 < 10){
        answer += "0";
    }
    answer += to_string(answertime / 3600);
    answertime %= 3600;
    answer += ":";
    if(answertime / 60 < 10){
        answer += "0";
    }
    answer += to_string(answertime / 60);
    answertime %= 60;
    answer += ":";
    if(answertime  < 10){
        answer += "0";
    }
    answer += to_string(answertime);
    return answer;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    //play_time 동영상 재생 시간 길이
    //adv_time 공익광고의 재생시간 길이
    //01234567
    //02:03:55
    
    vector<long long>Total_Play_Time(360001, 0);
    
    playtime += stoi(play_time.substr(6,2));
    playtime += stoi(play_time.substr(3,2)) * 60;
    playtime += stoi(play_time.substr(0,2)) * 60 * 60;
    //cout<<playtime<<endl;
    //00:14:15
    
    advtime += stoi(adv_time.substr(6,2));
    advtime += stoi(adv_time.substr(3,2)) * 60;
    advtime += stoi(adv_time.substr(0,2)) * 60 * 60;
    //cout<<advtime<<endl;
    
    for(int i = 0; i<logs.size(); i++){
        //logs가 300000개
        
        //01234567890123456
        //01:20:15-01:45:14
        
        string start = logs[i].substr(0, 8);
        string end = logs[i].substr(9, 8);
        
        int starttime = stoi(start.substr(0,2)) * 3600 + stoi(start.substr(3,2)) * 60 + stoi(start.substr(6,2));
        int endtime = stoi(end.substr(0,2)) * 3600 + stoi(end.substr(3,2)) * 60 + stoi(end.substr(6,2));
        
        Total_Play_Time[starttime] += 1;
        Total_Play_Time[endtime] -= 1;
    }
    
    for(int i = 1; i<=playtime; i++){

        Total_Play_Time[i] += Total_Play_Time[i - 1];
    }
    for(int i = 1; i<=playtime; i++){

        Total_Play_Time[i] += Total_Play_Time[i - 1];
    }
    
    long long max_view = Total_Play_Time[advtime - 1];  // 0초부터 시작
    long long answer_time = 0;
    
    for (int i = advtime; i <= playtime; i++) {
        long long current_view = Total_Play_Time[i] - Total_Play_Time[i - advtime];
        if (current_view > max_view) {
            max_view = current_view;
            answer_time = i - advtime + 1;
        }
    }
    
    answer = SetTime(answer_time);
    
    return answer;
}