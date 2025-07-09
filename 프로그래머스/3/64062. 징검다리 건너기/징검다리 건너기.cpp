#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool check(vector<int> stones, int k, int mid){
    
    int ch = 0;
    
    for(int i = 0; i<stones.size(); i++){
        if(stones[i] - mid <= 0){
            ch++;
        }
        else{
            ch = 0;
        }
        
        if(ch >= k){
            return false;
        }
        
    }
    
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int left = 0;
    int right = 0;
    for(int i = 0; i<stones.size(); i++){
        right = max(right, stones[i]);
    }
    
    while(left <= right){
        int mid = (left + right) / 2; //mid 값 구하기
        
        if(check(stones, k, mid)){
            //들어왔다는건 징검다리 건널 수 있다는거
            //사람 수를 더 늘려봐야함
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    
    answer = left;
    
    return answer;
}