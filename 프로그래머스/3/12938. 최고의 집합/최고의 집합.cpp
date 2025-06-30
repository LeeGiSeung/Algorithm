#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s){
        answer.push_back(-1);
        return answer;
    }
    
    int g = s / n;
    int h = s % n;
    
    for(int i = 0; i<n; i++){
        answer.push_back(g);
    }
    
    for(int i = answer.size() - 1; i > 0; i--){
        if(h > 0){
            answer[i]++;
            h--;
        }
    }
    
    //각 원소의 합이 S가 되는 수의 집합
    //위 조건을 만족하면서 각 원소의 곱이 최대가 되는 집합
    
    return answer;
}