#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long left = 0;
    long long right = 0;
    
    right = LLONG_MAX;
    answer = right;
    while(left <= right){
        long long mid = (left + right) / 2;
        //mid 시간으로 사람 몇 명을 볼 수 있는지
        long long count = 0;
        
        for(int i : times){
            count += mid / i;
            if(count >= n) break;
        }
        
        if(count >= n){
            answer = min(mid, answer);
            right = mid - 1;//좀 더 극한으로 줄여봄
        }
        else if(count < n){
            //부족하면 시간을 더 늘러야함
            left = mid + 1;
        }    
    }    
    
    return answer;
}