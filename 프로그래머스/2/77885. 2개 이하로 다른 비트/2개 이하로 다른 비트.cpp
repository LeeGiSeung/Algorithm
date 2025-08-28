#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    //1 numbers를 2진수로 변환
    //재귀를 통해 
    for(int i = 0; i<numbers.size(); i++){
        long long cur = numbers[i];
        if(cur % 2 == 0) answer.push_back(cur + 1);
        else{
            long long findone = (cur + 1) & (~cur);
            long long ans = ~(findone >> 1) & (cur | findone);
            answer.push_back(ans);
        }
    }
    
    return answer;
}