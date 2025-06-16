#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int solution(vector<int> a) {
    int answer = 0;
    
    if(a.size() <2) return 0;
    
    map<int,int> m;
    
    for(int i = 0; i<a.size(); i++){
        m[a[i]]++;
    }
    
    for(auto &[x,f] : m){
        if(f* 2 <= answer) continue; //계산해도 결과랑 같거나 작으면 할 필요가없음
        int cnt = 0;
        for(int i = 0; i<a.size() - 1; i++){
            if(a[i] == x || a[i + 1] == x){ //n번째로 많은 수 를 포함하고
                if(a[i] != a[i + 1]){ //두 수가 같지 않으면
                    cnt++;
                    i++;
                }
            }
        }
        answer = max(answer, (cnt * 2));
    }
    
    return answer;
}