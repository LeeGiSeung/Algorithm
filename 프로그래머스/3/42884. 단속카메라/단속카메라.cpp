#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool st(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end(), st);
    
    int end = routes[0][1];
    cout<<end<<endl;
    for(vector<int> v:routes){
        int start = v[0]; //현재 카메라의 시작
        if(start > end){ //현재 카메라가 이전 카메라보다 넘어가면
            answer++; //카메라 늘리고 현재 카메라를 이번 카메라의 end로 만듬
            end = v[1];
            cout<<end<<endl;
        }
    }
    
    return answer;
}