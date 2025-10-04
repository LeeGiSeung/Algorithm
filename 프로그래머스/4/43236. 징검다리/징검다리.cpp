#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    //[2, 14, 11, 21, 17]
    //2 11 14 17 21 원점에서부터 rocks 까지의 거리
    //
    int sz = rocks.size();
    
    int left = 0;
    int right = distance;
    //int n : 지울 수 있는 최대 돌 갯수
    
    while(left <= right){
        int mid = (left + right) / 2; //현재 뛰어다니는 거리
        int before = 0;
        int remove = 0; //지운 돌 수
        for(int i = 0; i<sz; i++){
            if(rocks[i] - before < mid){ //이전 돌에서 건너뛴 위치가 mid보다 작다는건 넘을 수 있다는거
                remove++;
            }
            else{
                //크거나 같다는건 돌을 밟거나 나아가야 한다는거임
                before = rocks[i];
            }
        }
        
        if(distance - before < mid){
            remove++;
        }
        
        /*
        0 2 11 14 25
        2 9 3 11 //마지막 11은 마지막돌 ~ 도착지점까지의 거리임 이건 따로 계산
        */
        
        if(remove <= n){
            //n이하면 일단 정답 확인
            answer = max(answer, mid);
            //mid를 더 올려봄
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
        
        
    }
    
    return answer;
}