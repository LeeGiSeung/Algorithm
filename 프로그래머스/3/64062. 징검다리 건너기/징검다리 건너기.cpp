#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    //k = 한번에 건너뛸 수 있는 돌의 개수
    
    //건널 수 있는 사람의 최대수는 stones의 최대수임
    
    int left = 0;
    int right = 0;
    
    for(int i = 0; i<stones.size(); i++){
        right = max(stones[i], right);
    }
    
    while(left <= right){
        int mid = (right + left) / 2;
        //mid로 검사
        int null = 0;
        bool check = true;
        //cout<<left<<" "<<mid<<" "<<right<<endl;
        for(int i = 0; i<stones.size(); i++){
            
            if(stones[i] - mid < 0) null++;
            else null = 0;
                
            if(null >= k){
                check = false;
                break;
            }
        }
        
        if(!check){
            //징검다리 간격이 너무 큼 이러면 mid를 줄여야함
            right = mid - 1;
        }
        else{
            left = mid + 1; // mid를 좀 더 키워봄
            answer = max(mid, answer);
        }
    }
    
    return answer;
}