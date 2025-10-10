#include<vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

long long solution(vector<vector<int> > land, int P, int Q) {
    long long answer = LLONG_MAX;
    
    //블럭의 위치는 상관없이 블럭의 높이가 중요한거임
    vector<long long> v;
    int mx = 0;
    int n = land.size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            v.push_back(land[i][j]);
            mx = max(land[i][j], mx);
        }
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int curblock = 0;
    
    long long tmp = 0;
    
    for(int i = 0; i<n*n; i++){
        if(v[i] == mx) curblock++; //최상 블럭과 같은 블럭이면 해당블럭은 시작할때 계산 안해도딤
        else{
            tmp += (mx - v[i]) * P;
        }
    }
    int block = n * n;
    answer = tmp;
    //각 계단이 층이라고 생각하면된다
    for(int i = curblock; i<n*n; i++){
        //i 가 vector v에서의 index임
        if(mx == v[i]) curblock++; //만약 현재 층 값이 최대값과 같으면 계산할 필요없 그냥 넘김
        else{
            //curblock 자기 위로 설치된 블록
            //block 전체 블록
            //block - curblock 앞으로 남은 블록
            
            //여기 들어왔다는건 층이 바뀌엿다는거
            //근데 내림차순이니까 무조건 적은 층이 들어온거임 
            //블럭 추가 P, 블럭 제거 Q
            //구해야 하는 층 * 움직어야 하는 블럭 양
            tmp += (mx - v[i]) * (Q*(curblock)-P*(block-curblock)); 
            answer = min(answer, tmp);
            mx = v[i]; //현재 층 변경
            curblock++;
        }
    }
    
    return answer;
}