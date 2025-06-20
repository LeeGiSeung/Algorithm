#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
int answer = 0;

int solution(int n, vector<int> cores) {
    
    if(n <= cores.size()){ //제시하는 작업이 cores 보다 작으면 바로 return
        return n;
    }
    vector<int> v;
    v = cores;
    sort(v.begin(), v.end());
    int left = 0;
    int right = 500000001;
    int mid = 0;
    
    while(left <= right){
        mid = (left + right) / 2;
        int count = cores.size();
        for(int i = 0; i<cores.size(); i++){
            count += mid / cores[i];
            
            if(count >= n){
                break;
            }
        }
        
        if(count >= n){
            //더 많은걸 지우고있으면
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    //mid : 모든 작업을 끝낸 시간
    int count = cores.size();
    for(int i = 0; i<cores.size(); i++){
        count += right / cores[i]; //해결한 갯수를 셈
    }
    
    for(int i = 0; i<cores.size(); i++){
        if((right + 1) % cores[i] == 0){
            count++;
        }
        if(count == n){
            return i + 1;
        }
    }
    
    return answer;
}