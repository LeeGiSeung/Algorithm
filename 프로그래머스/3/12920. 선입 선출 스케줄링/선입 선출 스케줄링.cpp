#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    long long time = 0;
    long long mid = 0;
    if(n - cores.size() <= 0) return n;
    long long count = 0;
    long long left = 0;
    long long right = 100000000;
    while(left <= right){
        mid = (right + left) / 2;

        count = cores.size(); //처음에 3개는 모두 채울 수 있으니까
        //n 해결해야 할 일거리
        for(int i = 0; i<cores.size(); i++){
            count += mid / cores[i]; //해당 시간으로 할 수 있는 일거리
            if(count >= n) break;
        }
        
        if(count >= n){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    count = cores.size();
    for(int i = 0; i<cores.size(); i++){
        count += right / cores[i];
    }
    cout<<left<<endl;
    cout<<count<<endl;
    for(int i = 0; i<cores.size(); i++){
        if((right + 1) % cores[i] == 0) count++;
        if(count == n) return i + 1;
    }
    
    return answer;
}