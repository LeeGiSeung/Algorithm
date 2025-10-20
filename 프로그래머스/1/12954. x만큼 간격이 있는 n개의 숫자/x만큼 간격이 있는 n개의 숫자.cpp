#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int _x, int n) {
    vector<long long> answer;
    
    long long x = _x;
    
    while(answer.size() < n){
        answer.push_back(x);
        x += _x;
    }
    
    return answer;
}