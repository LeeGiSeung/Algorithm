#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> minleft(a.size());
    vector<int> minright(a.size());
    //풍선들을 1개만 남을 때까지 터트렸을 때 최후까지 남기는 것이 가능한 풍선들의 개수
    
    //자신들의 좌/우 에 작은것들이 1개만 있으면 됨
    int m = INT_MAX;
    for(int i = 0; i<a.size(); i++){
        m = min(m, a[i]);
        minleft[i] = m; //left를 기준으로 m정리
    }
    
    m = INT_MAX;
    for(int i = a.size() - 1; i >= 0; i--){
        m = min(m, a[i]);
        minright[i] = m; //left를 기준으로 m정리
    }

    for(int i = 0; i<a.size(); i++){
        if(i == 0 || i == a.size() - 1) answer++; //양끝이면 무조건 됨
        else{
            int count = 0;
            int left = minleft[i - 1];
            int mid = a[i];
            int right = minright[i + 1];
            
            if(left < mid) count++;
            if(right < mid) count++;
            
            if(count < 2){
                answer++;
            }
            
        }
    }
    
    return answer;
}