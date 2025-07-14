#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 0;
    int mx = 0;
    for(int i = 0; i<times.size(); i++){
        mx = max(mx, times[i]);
    }
    
    long long right = 1ll * mx * n;

    while(left <= right){
        long long mid = (left + right) / 2;
        long long count = 0;
        
        for(int i = 0; i<times.size(); i++){
            count += mid / times[i];
        }
        
        if(count >= n){
            answer = left;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    answer = left;
    
    return answer;
}