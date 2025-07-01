#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    //최소 몇 대의 카메라를 설치해야 하는지를
    sort(routes.begin(), routes.end());
    
    int camera = routes[0][1];
    answer++;
    
    for(int i = 1; i<routes.size(); i++){
        //카메라 들어오는 위치가 camera보다 크면
        //카메라 새로 설치해야함
        if(routes[i][0] > camera){ 
            camera = routes[i][1]; //새로운 카메라의 제한은 현재 카메라가 끝나는 부분 
            answer++; //카메라 증가
        }
        else if(routes[i][1] < camera){
            camera = routes[i][1];
        }
    }
    
    return answer;
}