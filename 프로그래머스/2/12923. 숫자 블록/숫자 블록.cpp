#include <string>
#include <vector>

using namespace std;

long long solve(long long n){
    
    long long i = 2; long long res = 1;
    while(i * i <= n){
        if(n % i == 0){
            res = i;
            if(n / i <= 100000000) return (n / i);
        }
        i++;
    }
    
    return res;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    //시장님은 특정 구간에 어떤 블록이 깔려 있는지 알고 싶습니다
    
    //end - begin ≤ 5,000
    
    for(long long i = begin; i<=end; i++){
        if(i == 1) answer.push_back(0);
        else{
            answer.push_back(solve(i));
        }
    }
    
    return answer;
}