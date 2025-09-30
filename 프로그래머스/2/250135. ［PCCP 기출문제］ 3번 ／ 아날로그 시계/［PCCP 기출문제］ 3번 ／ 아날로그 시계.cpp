#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    int starttime = h1*3600 + m1*60 + s1;
    int endtime = h2*3600 + m2*60 + s2;
    
    if(starttime == 0 || starttime == 12*3600){ //12시 정각에 시계가 있으면 초침이 분침/ 시침과 같이 있는거임
        answer++; //알람이 울린 횟수 -> 초침이 시침,분침과 겹쳐있으면 알람이 1번 울림 동시에 3개가 겹친거
    }
    
    
    while(starttime < endtime){
        //starttime 으로 시침, 분침 , 초침 각도 계산
        
        double curhourangle = fmod(starttime / 120.0 , 360.0); //시침 1시간은 30도 = 3600초에 30도
        double curminangle = fmod(starttime / 10.0 , 360.0); //분침 1분은 6도 360초에 6도
        double cursecangle = fmod(starttime * 6.0 , 360.0);  //초침 1초는 한번 지나갈때 6도임
        
        double nexthourangle;
        double nextminangle;
        double nextsecangle;
        
        if(fmod((starttime + 1) / 120.0 , 360.0) == 0) nexthourangle = 360; //0도 이상가면 360도 고정
        //0도와 360도가 논리적으로 맞지만 "지나쳤다" 라는걸 판독하기위해서는 0도로 하면 >= 이거에 걸리지않음
        else nexthourangle = fmod((starttime + 1) / 120.0 , 360.0);
        
        if(fmod((starttime + 1) / 10.0 , 360.0) == 0) nextminangle = 360;
        else nextminangle = fmod((starttime + 1) / 10.0 , 360.0);
            
        if(fmod((starttime + 1) * 6.0 , 360.0) == 0) nextsecangle = 360;
        else nextsecangle = fmod((starttime + 1) * 6.0 , 360.0);
        
        if(cursecangle < curminangle && nextsecangle >= nextminangle) answer++;
        if(cursecangle < curhourangle && nextsecangle >= nexthourangle) answer++;
        
        //만약 시, 분 ,초 침이 다같이 있으면 알람이 두번 울리는게 아니라 1번만 울려야함
        if(nextsecangle == nextminangle && nextsecangle == nexthourangle) answer--;
        
        starttime++;
    }
    
    return answer;
}