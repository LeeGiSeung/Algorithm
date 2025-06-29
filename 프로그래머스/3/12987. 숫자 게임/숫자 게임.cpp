#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool check[1000000001];

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    //b팀이 얻을 수 있는 최대 점수
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int a_size = A.size();
    int b_size = B.size();
    int b_index = 0;
    int a_index = 0;
    //제일 큰놈은 제일 큰놈으로
    while(a_index < a_size && b_index < b_size)
    {
        if(A[a_index] < B[b_index]){
            answer++;
            b_index++;
            a_index++;
        } 
        else{
            b_index++;
        }
    }
    
    return answer;
}