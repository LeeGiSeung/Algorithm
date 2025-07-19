#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> left_v(1000001);
vector<int> right_v(1000001);

int solution(vector<int> a) {
    int answer = 0;
    int leftmin = a[0];
    for(int i = 0; i<a.size(); i++){
        if(a[i] < leftmin) leftmin = a[i];
        left_v[i] = leftmin;
    }
    
    int rightmin = a[a.size() - 1];
    for(int i = a.size() - 1; i >= 0; i--){
        if(a[i] < rightmin) rightmin = a[i];
        right_v[i] = rightmin;
    }
    
    for(int i = 0; i<a.size(); i++){
        if(left_v[i] >= a[i] || right_v[i] >= a[i]) answer++;
    }
    
    return answer;
}