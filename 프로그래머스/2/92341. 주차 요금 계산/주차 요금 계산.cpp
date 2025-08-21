#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
struct Data{
    int carnumber;
    int allsecond = 0;
    int second;
    int in;
};

Data make_time(string time){
    Data cur;
    cur.second = 0;
    cur.carnumber = 0;
    cur.in = false;
    
    //시간
    cur.second += stoi(time.substr(0,2)) * 3600;
    cur.second += stoi(time.substr(3,2)) * 60;

    //차 번호
    cur.carnumber = stoi(time.substr(6,4));
    
    //출입
    if(time.substr(11,2) == "IN") cur.in = true; 
    else cur.in = false;
        
    return cur;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int,Data> m;
    
    //입차하고 출차된것 까지 봐야함
    
    for(int i = 0; i<records.size(); i++){
        Data cur = make_time(records[i]);
        int carnumber = cur.carnumber;
        int second = cur.second;
        int in = cur.in;
        if(in == true){ //입차면 map에 등록
            m[carnumber].second = second;
            m[carnumber].in = true;
        }
        else if(in == false){ //출차면 출차 등록하고 시간 계산해서 넣기
            int tempsecond = m[carnumber].second; //옛날 시간
            m[carnumber].allsecond += second - tempsecond; //map에 추가된 시간 추가
            
            m[carnumber].second = 0; //시간 초과
            m[carnumber].in = false; //출차 설정
        }
    }
    
    string es = "23:59";
    int endtime = 0;
    //시간
    endtime += stoi(es.substr(0,2)) * 3600;
    endtime += stoi(es.substr(3,2)) * 60;

    
    for(auto &i : m){
        if(i.second.in){ //출고 처리가 안된 게 있으면
            i.second.allsecond += endtime - i.second.second; //23:59 기준으로 출고처리진행
            i.second.second = 0;
            i.second.in = false;
        }
    }
    for(auto &i : m){
        int minute = i.second.allsecond / 60;
        if(minute <= fees[0]){ //기본 시간보다 작으면
            answer.push_back(fees[1]); //기본 요금
        }
        else{ //아니면 기본 요금 추가 + 추가 요금
            answer.push_back(fees[1]); //기본 요금
            i.second.allsecond -= 60 * fees[0]; //기본 시간 제외하고 추가요금 계산
            answer.back() += ((i.second.allsecond / 60) / fees[2]) * fees[3];
            if((i.second.allsecond / 60) % fees[2] > 0){
                answer.back() += fees[3];
            }
        }
    }
    //어떤 차량이 입차된 후에 출차된 내역이 없다면, 23:59에 출차된 것으로 간주합니다.
    //차량 번호가 작은 자동차부터 청구할 주차 요금
    return answer;
}