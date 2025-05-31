#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    //09 부터 총 n회 t간격으로 도착한다. 셔틀하나에 m명의 승객이 탈 수 있다.
    
    //timetable : 크루원들이 도착한 시간
    sort(timetable.begin(), timetable.end());
    vector<int> timeint;
    
    //01234
    //09:00
    
    for(int i = 0; i<timetable.size(); i++){
        timeint.push_back(stoi(timetable[i].substr(0,2)) * 60 + stoi(timetable[i].substr(3,2)));
    }
    
    int index = 0;
    int bustime = 540;
    int result = 0;
    int crewboard = 0; //탑승한 크루
    for(int i = 1; i<=n; i++){
        crewboard = 0;
        while(crewboard < m && index < timetable.size()){
            if(timeint[index] <= bustime){
                index++;
                crewboard++;
            }
            else{
                break;
            }
        }
        if(i == n){
            if(crewboard < m){
        result = bustime;
    }
    else{
        result = timeint[index - 1] - 1;
    }
        }

        bustime += t;
        
    }
    

    
    int hour = result / 60;
    
    if(hour < 10){
        answer += "0";
        answer += to_string(hour);
    }
    else{
        answer += to_string(hour);
    }
    
    int minutes = result % 60;
    answer += ":";
    
    if(minutes < 10){
        answer += "0";
        answer += to_string(minutes);
    }
    else{
        answer += to_string(minutes);
    }
    
    return answer;
}