#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solve(long long n){
    if(n == 1) return 0;
    long long i = 2;
    long long res = 1;
    
    while(i * i <= n){ //최적화를 위해
        if(n % i == 0){ //약수가 되면
            res = i;
            if(n / i <= 10000000) return (n / i);
        }
        i++;
    }
    
    return res;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(long long i = begin; i<=end; i++){
        answer.push_back(solve(i));
    }
    
    return answer;
}