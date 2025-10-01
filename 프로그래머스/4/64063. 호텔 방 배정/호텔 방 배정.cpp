#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long, long long> m;

long long find_next(long long cur){
    if(m[cur] == 0) return cur;
    return m[cur] = find_next(m[cur]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(int i = 0; i<room_number.size(); i++){
        long long num = room_number[i];
        
        long long next_num = find_next(num);
        answer.push_back(next_num);
        m[next_num] = next_num + 1;
    }
    
    return answer;
}